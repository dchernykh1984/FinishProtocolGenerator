#include <sys/timeb.h>
#include <time.h>
#include < stdio.h >
#include <string.h> 
#include < stdlib.h >
#include < vcclr.h >
#include <math.h>
#include <direct.h>
#include < vcclr.h >

using namespace System;

namespace FinishProtocolGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	public ref class LoggerSTC {
	public:
		int static const numberOfCharsInString = 5000;
		double static timeExecution = 0;
		int static logFileNumber = 0;
		int static const STATUS_INFO = 0;
		int static const STATUS_ERROR = 1;
		int static const STATUS_ENTER_FUNCTION = 2;
		int static const STATUS_EXIT_FUNCTION = 3;
		int static const STATUS_WARNING = 4;
		int static const STATUS_ALWAYS_WRITE = 5;
		static int numberOfInfoMessages;
		static int numberOfErrors;
		static int numberOfStartedMethods;
		static int numberOfCompletedMethods;
		static int numberOfWarnings;
		static bool useFileLogger;
		static bool useInterfaceLogger;
		static bool writeErrAndWrnOnly;
		static ListBox^ loggerListBox;
		static Label^ infoLabel;

	public: static void initialiseLogger(bool errAndWrnOnly,bool setUseFileLogger, bool setUseInterfaceLogger, ListBox^ formLoggerListBox, Label^ formInfoLabel) {
				numberOfInfoMessages = 0;
				numberOfErrors = 0;
				numberOfStartedMethods = 0;
				numberOfCompletedMethods = 0;
				numberOfWarnings = 0;
				useFileLogger = setUseFileLogger;
				useInterfaceLogger = setUseInterfaceLogger;
				loggerListBox = formLoggerListBox;
				infoLabel = formInfoLabel;
				writeErrAndWrnOnly = errAndWrnOnly;
				loggerListBox->Items->Clear();
			 	 struct _timeb timer;
				 _ftime(&timer);
				 timeExecution = timer.time + timer.millitm/1000.0;

				if(useFileLogger) {
						_mkdir("temp");
						FILE* resultLoggerFile;
						logFileNumber++;
						resultLoggerFile = fopen(getCharArrayFromString(gcnew String("temp\\fpg")
							+ logFileNumber.ToString() + gcnew String(".txt")),"w+");
						fclose(resultLoggerFile);
				}
				infoLabel->ForeColor = System::Drawing::Color::Black;
				if(useFileLogger && !useInterfaceLogger) {
					infoLabel->Text = gcnew String("See log at temp\\fpg.txt"); 
				}
			}
	public: 
		static char* getCharArrayFromString(String^ inputString) {
			char* pString = (char*)System::Runtime::InteropServices::Marshal:: StringToHGlobalAnsi(inputString).ToPointer();
			return pString;
		 }
	public:
		static inline void PrintTime(String^ operationName) {
			 	 struct _timeb timer;
				 _ftime(&timer);
				 double timeDifference = timer.time + timer.millitm/1000.0 - timeExecution;
				 writeLog(STATUS_ALWAYS_WRITE, operationName + gcnew String(": ") + timeDifference.ToString() + gcnew String(" seconds"));
				 timeExecution = timer.time + timer.millitm/1000.0;
		}
	public: 
		static inline void writeLog(int status, String^ inputString) {
			if(useFileLogger) {
			FILE* resultLoggerFile;
			if((status == STATUS_ALWAYS_WRITE)||(status == STATUS_WARNING)||(status == STATUS_EXIT_FUNCTION && !writeErrAndWrnOnly)||
				(status == STATUS_ENTER_FUNCTION && !writeErrAndWrnOnly)||
				(status == STATUS_ERROR)||(status == STATUS_INFO && !writeErrAndWrnOnly)) {
				resultLoggerFile = fopen(getCharArrayFromString(gcnew String("temp\\fpg")
							+ logFileNumber.ToString() + gcnew String(".txt")),"a+");
			}
			if(status == STATUS_ALWAYS_WRITE) {
				 fprintf(resultLoggerFile,getCharArrayFromString(inputString));
				 fprintf(resultLoggerFile,"\n");
			}
			if(status == STATUS_INFO && !writeErrAndWrnOnly) {
					fprintf(resultLoggerFile,"INFO: ");
				 fprintf(resultLoggerFile,getCharArrayFromString(inputString));
				 fprintf(resultLoggerFile,"\n");
				} else if(status == STATUS_ERROR) {
					fprintf(resultLoggerFile,"ERROR: ");
				 fprintf(resultLoggerFile,getCharArrayFromString(inputString));
				 fprintf(resultLoggerFile,"\n");
				} else if(status == STATUS_ENTER_FUNCTION && !writeErrAndWrnOnly) {
					fprintf(resultLoggerFile,"ENTER_FUNCTION: ");
				 fprintf(resultLoggerFile,getCharArrayFromString(inputString));
				 fprintf(resultLoggerFile,"\n");
				} else if(status == STATUS_EXIT_FUNCTION && !writeErrAndWrnOnly) {
					fprintf(resultLoggerFile,"EXIT_FUNCTION: ");
				 fprintf(resultLoggerFile,getCharArrayFromString(inputString));
				 fprintf(resultLoggerFile,"\n");
				} else if(status == STATUS_WARNING) {
					fprintf(resultLoggerFile,"WARNING: ");
				 fprintf(resultLoggerFile,getCharArrayFromString(inputString));
				 fprintf(resultLoggerFile,"\n");
				}
			if((status == STATUS_WARNING)||(status == STATUS_EXIT_FUNCTION && !writeErrAndWrnOnly)||
				(status == STATUS_ENTER_FUNCTION && !writeErrAndWrnOnly)||
				(status == STATUS_ERROR)||(status == STATUS_INFO && !writeErrAndWrnOnly)) {
				fclose(resultLoggerFile);
			}

			}
			if(useInterfaceLogger) {
				if(status == STATUS_ALWAYS_WRITE) {
					loggerListBox->Items->Add(inputString);
					numberOfInfoMessages++;
				}
				if(status == STATUS_INFO && !writeErrAndWrnOnly) {
					loggerListBox->Items->Add(gcnew String("INFO: ") + inputString);
					numberOfInfoMessages++;
				} else if(status == STATUS_ERROR) {
					loggerListBox->Items->Add(gcnew String("ERROR: ") + inputString);
					numberOfErrors++;
				} else if(status == STATUS_ENTER_FUNCTION && !writeErrAndWrnOnly) {
					loggerListBox->Items->Add(gcnew String("ENTER_FUNCTION: ") + inputString);
					numberOfStartedMethods++;
				} else if(status == STATUS_EXIT_FUNCTION && !writeErrAndWrnOnly) {
					loggerListBox->Items->Add(gcnew String("EXIT_FUNCTION: ") + inputString);
					numberOfCompletedMethods++;
				} else if(status == STATUS_WARNING) {
					loggerListBox->Items->Add(gcnew String("WARNING: ") + inputString);
					numberOfWarnings++;
				}
				infoLabel->Text = gcnew String("Errors - ") + numberOfErrors.ToString() + gcnew String("; Warnings - ") + numberOfWarnings.ToString();
//				if(useFileLogger) {
//					infoLabel->Text = infoLabel->Text + gcnew String(". See log at temp\\fpg.txt"); 
//				}
				if(numberOfErrors!=0) {
					infoLabel->ForeColor = System::Drawing::Color::Red;
				} else if (numberOfWarnings!=0) {
					infoLabel->ForeColor = System::Drawing::Color::OrangeRed;
				} else {
					infoLabel->ForeColor = System::Drawing::Color::Green;
				}
			}

		}
	};

		 public class ProtocolStringParser {
		 public:
			 static int getDigitFromChar(char digitChar) {
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter function getDigitFromChar(char digitChar) with parameter \"") + gcnew String(&digitChar) + gcnew String("\""));
				 if(digitChar<='9' && digitChar>='0') {
					 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit function getDigitFromChar(char digitChar), resutl \"") + (gcnew Int32(digitChar-'0'))->ToString() + gcnew String("\""));
					return digitChar-'0';
				 } else {
					 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String(&digitChar) + gcnew String(" is not a digit"));
					 return -1;
				 }
			 }
			 static int getIntByString(char* inputString) {
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter function getIntByString(char* inputString) with parameter \"") + gcnew String(inputString) + gcnew String("\""));
				 int result = 0;
				 int i = 0;
				 while(inputString[i]!=0) {
					 if(getDigitFromChar(inputString[i]) == -1) {
						 char nonDigitChar = inputString[i];
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String(inputString) + gcnew String(" includes non-digit symbol \"") + gcnew String(&nonDigitChar) + gcnew String("\""));
						 return -1;
					 }
					 result = result*10+getDigitFromChar(inputString[i]);
					 i++;
				 }
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit function getIntByString(char* inputString), return \"") + result.ToString() + gcnew String("\""));
				 return result;
			 }

			 static bool validateTimeString(char* timeString) {
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter function validateTimeString(char* timeString) with parameter \"") + gcnew String(timeString) + gcnew String("\""));
				 int i = 0;
				 int daysHoursDeliminerPosition;
				 int hoursMinutesDeliminerPosition;
				 int minutesSecondsDeliminerPosition;
				 int secondsFracturesDeliminerPosition;
				 int endOfStringPosition;
				 while(timeString[i]!=' ') {
					 if(timeString[i] == 0) {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Deliminer ' ' between days and hours not found in timeString \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 } else if(getDigitFromChar(timeString[i]) == -1) {
						 char nonDigitChar = timeString[i];
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Symbol '") + gcnew String(&nonDigitChar) + gcnew String("' is not a digit in string \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 }
					 i++;
				 }
				 daysHoursDeliminerPosition = i;
				 i++;
				 while(timeString[i]!=':') {
					 if(timeString[i] == 0) {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Deliminer ':' between days and hours not found in timeString \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 } else if(getDigitFromChar(timeString[i]) == -1) {
						 char nonDigitChar = timeString[i];
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Symbol '") + gcnew String(&nonDigitChar) + gcnew String("' is not a digit in string \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 }
					 i++;
				 }
				 hoursMinutesDeliminerPosition = i;
				 i++;
				 while(timeString[i]!=':') {
					 if(timeString[i] == 0) {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Deliminer ':' between days and hours not found in timeString \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 } else if(getDigitFromChar(timeString[i]) == -1) {
						 char nonDigitChar = timeString[i];
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Symbol '") + gcnew String(&nonDigitChar) + gcnew String("' is not a digit in string \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 }
					 i++;
				 }
				 minutesSecondsDeliminerPosition = i;
				 i++;
				 while(timeString[i]!='.') {
					 if(timeString[i] == 0) {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Deliminer '.' between days and hours not found in timeString \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 } else if(getDigitFromChar(timeString[i]) == -1) {
						 char nonDigitChar = timeString[i];
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Symbol '") + gcnew String(&nonDigitChar) + gcnew String("' is not a digit in string \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 }
					 i++;
				 }
				 secondsFracturesDeliminerPosition = i;
				 i++;
				 while(timeString[i]!=0) {
					 if(getDigitFromChar(timeString[i]) == -1) {
						 char nonDigitChar = timeString[i];
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Symbol '") + gcnew String(&nonDigitChar) + gcnew String("' is not a digit in string \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
					 }
					 i++;
				 }
				 endOfStringPosition = i;
				 if(daysHoursDeliminerPosition<=0 
					 || hoursMinutesDeliminerPosition-daysHoursDeliminerPosition <= 1
					 || hoursMinutesDeliminerPosition-daysHoursDeliminerPosition > 3
					 || minutesSecondsDeliminerPosition-hoursMinutesDeliminerPosition <= 1
					 || minutesSecondsDeliminerPosition-hoursMinutesDeliminerPosition > 3
					 || secondsFracturesDeliminerPosition-minutesSecondsDeliminerPosition <=1
					 || secondsFracturesDeliminerPosition-minutesSecondsDeliminerPosition >3
					 || endOfStringPosition-secondsFracturesDeliminerPosition <=1) {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Wrong sizes of fields \"days\", \"hours\", \"minutes\", \"seconds\" or \"fractions\" in string \"") + gcnew String(timeString) + gcnew String("\""));
						 return false;
				 }
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit function validateTimeString(char* timeString), return true"));
				 return true;
			 }
			 static double getSecondsByTime(char* timeString) {
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter function getSecondsByTime(char* timeString) with parameter \"") + gcnew String(timeString) + gcnew String("\""));
				 int  i = 0;
				 double days = 0.0;
				 double hours = 0.0;
				 double minutes = 0.0;
				 double seconds = 0.0;
				 double milliseconds = 0.0;
				 double millisecondsPow = 1.0;
				 if(!validateTimeString(timeString)) {
					LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Not valid timeString format \"") + gcnew String(timeString) + gcnew String("\""));
					return 0;
				 }

				 while(timeString[i]!=' ') {
					 days = days*10+getDigitFromChar(timeString[i]);
					 i++;
				 }
				 i++;
				 while(timeString[i]!=':') {
					 hours = hours*10+getDigitFromChar(timeString[i]);
					 i++;
				 }
				 i++;
				 while(timeString[i]!=':') {
					 minutes = minutes*10+getDigitFromChar(timeString[i]);
					 i++;
				 }
				 i++;
				 while(timeString[i]!='.') {
					 seconds = seconds*10+getDigitFromChar(timeString[i]);
					 i++;
				 }
				 i++;

				 while(timeString[i]!=0) {
					 milliseconds = milliseconds*10+getDigitFromChar(timeString[i]);
					 millisecondsPow = millisecondsPow*10;
					 i++;
				 }
				 milliseconds /= millisecondsPow;
				 double result = days*86400.0+hours*3600.0+minutes*60.0+seconds+milliseconds;
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit function getSecondsByTime(char* timeString), return \"") + result.ToString() + gcnew String("\""));
				 return result;
			 }

			 static int getNumberOfFields(char* inputString, char parser) {
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter function getNumberOfFields(char* inputString, char parser) with parameters \"") + gcnew String(inputString) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 int i = 0;
				 int numberOfFields = 0;
				 while(inputString[i]!=0) {
					 if(inputString[i]==parser) {
						 numberOfFields++;
					 }
					 i++;
				 }
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit function getNumberOfFields(char* inputString, char parser) with parameters \"") + gcnew String(inputString) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 return numberOfFields;
			 }
			 static char* getFieldByNumber(char* inputString,int fieldNubmer, char parser) {
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter function getFieldByNumber(char* inputString,int fieldNubmer, char parser) with parameters \"") + gcnew String(inputString) + gcnew String("\", \"") + fieldNubmer.ToString() + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 int fieldCounter = 0;
				 int stringStart;
				 int stringFinish;
				 char* fieldValue;
				 int i = 0;
				 if(fieldNubmer >= getNumberOfFields(inputString,parser)) {
					LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Trying to get field \"") + fieldNubmer.ToString() + gcnew String("\" that is more than number of fields in string \"") + gcnew String(inputString) + gcnew String("\", using parser \"") + gcnew String(&parser) + gcnew String("\""));
					fieldValue = new char[2];
					fieldValue[0] = '0';
					fieldValue[1] = 0;
					return fieldValue;
				 }
				 while(inputString[i]!=0) {
					 if(fieldNubmer==0) {
						 stringStart = 0;
						 break;
					 }
					 if(inputString[i]==parser) {
						 fieldCounter++;
						 if(fieldCounter == fieldNubmer) {
							 stringStart = i+1;
							 i++;
							 break;
						 }
					 }
					 i++;
				 }
				 while(inputString[i]!=0) {
					 if(inputString[i]==parser) {
						 stringFinish = i-1;
						 break;
					 }
					 i++;
				 }
				 fieldValue = new char[stringFinish-stringStart+2];
				 for(int j = 0;j<stringFinish-stringStart+1;j++) {
					 fieldValue[j] = inputString[stringStart+j];
				 }
				 fieldValue[stringFinish-stringStart+1] =0;
				 if(!LoggerSTC::writeErrAndWrnOnly) LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit function getFieldByNumber(char* inputString,int fieldNubmer, char parser) with parameters \"") + gcnew String(inputString) + gcnew String("\", \"") + fieldNubmer.ToString() + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 return fieldValue;
			 }
		 };
	class StartProtocolElement {
		 public:
			 char* competitorID;
			 char* groupID;
			 char* competitorName;
			 char* competitorYearOfBirth;
			 char* competitorTeam;
			 char* competitorCity;
			 char* competitorAdditionalInfo;
			 double startDelay;
			 int stagesNumber;
			 int numberOfLaps;
			 StartProtocolElement (){
				 competitorID = new char();
				 groupID = new char();
				 competitorName = new char();
				 stagesNumber = 0;
				 competitorYearOfBirth = new char();
				 competitorTeam = new char();
				 competitorCity = new char();
				 numberOfLaps = 0;
				 startDelay = 0;
			 }
			 ~StartProtocolElement (){
				 delete competitorID;
				 delete groupID;
				 delete competitorName;
				 delete competitorYearOfBirth;
				 delete competitorTeam;
				 delete competitorCity;
			 }
			 StartProtocolElement (char* stringToParse, char parser, bool firstLapWillBeRemovedInFuture, bool eliminatorFinals) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter constructor StartProtocolElement (char* stringToParse, char parser) with parameters \"") + gcnew String(stringToParse) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 competitorID = ProtocolStringParser::getFieldByNumber(stringToParse,0,parser);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("CompetitorID is \"") + gcnew String(competitorID) + gcnew String("\""));
				 competitorName = ProtocolStringParser::getFieldByNumber(stringToParse,1,parser);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("CompetitorName is \"") + gcnew String(competitorName) + gcnew String("\""));
				 groupID = ProtocolStringParser::getFieldByNumber(stringToParse,2,parser);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("GroupID is \"") + gcnew String(groupID) + gcnew String("\""));
				 numberOfLaps = ProtocolStringParser::getIntByString(ProtocolStringParser::getFieldByNumber(stringToParse,3,parser)) + (firstLapWillBeRemovedInFuture?1:0);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Number of laps is \"") + numberOfLaps.ToString() + gcnew String("\""));
				 stagesNumber = ProtocolStringParser::getIntByString(ProtocolStringParser::getFieldByNumber(stringToParse,4,parser));
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Stages number is \"") + stagesNumber.ToString() + gcnew String("\""));
				 competitorYearOfBirth = ProtocolStringParser::getFieldByNumber(stringToParse,5,parser);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Competitor year of birth is \"") + gcnew String(competitorYearOfBirth) + gcnew String("\""));
				 competitorTeam = ProtocolStringParser::getFieldByNumber(stringToParse,6,parser);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Competitor team is is \"") + gcnew String(competitorTeam) + gcnew String("\""));
				 competitorCity = ProtocolStringParser::getFieldByNumber(stringToParse,7,parser);
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Competitor's city is \"") + gcnew String(competitorCity) + gcnew String("\""));
				 if(ProtocolStringParser::getNumberOfFields(stringToParse,parser)>8) {
					 competitorAdditionalInfo = ProtocolStringParser::getFieldByNumber(stringToParse,8,parser);
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Competitor's additional info is \"") + gcnew String(competitorCity) + gcnew String("\""));
				 } else {
					 competitorAdditionalInfo = "";
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("No additional info about competitor"));
				 }
				 if(ProtocolStringParser::getNumberOfFields(stringToParse,parser)>9) {
					 if(eliminatorFinals) {
						 startDelay = ProtocolStringParser::getIntByString(ProtocolStringParser::getFieldByNumber(stringToParse,9,parser));
//						 LoggerSTC::writeLog(LoggerSTC::STATUS_ALWAYS_WRITE,startDelay.ToString());
					 } else {
						 if(ProtocolStringParser::validateTimeString(ProtocolStringParser::getFieldByNumber(stringToParse,9,parser))) {
								 startDelay = ProtocolStringParser::getSecondsByTime(ProtocolStringParser::getFieldByNumber(stringToParse,9,parser));
							LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Competitor's start delay is \"") + gcnew String(ProtocolStringParser::getFieldByNumber(stringToParse,9,parser)) + gcnew String("\""));
						 } else {
							LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Wrong format of time string:\"") + gcnew String(ProtocolStringParser::getFieldByNumber(stringToParse,9,parser)) + gcnew String("\""));
							startDelay = 0;
						 }
					 }
				 } else {
					 startDelay = 0;
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("No start delay for competitor found"));
				 }
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit constructor StartProtocolElement (char* stringToParse, char parser) with parameters \"") + gcnew String(stringToParse) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
			 }
		 };
	class FinalRound {
	public:
		char** numbers;
		int roundSize;
		bool filledNumbers;
		bool filledResults;
		int* previousPlaces;
		bool* finishedCompetitors;
		FinalRound** previousRounds;
		FinalRound(int numberOfCompetitors) {
			roundSize = numberOfCompetitors;
			numbers = new char*[roundSize];
			filledNumbers = false;
			filledResults = false;
			previousPlaces = new int[roundSize];
			finishedCompetitors = new bool[roundSize];
			for(int i = 0;i<roundSize;i++) {
				numbers[i] = "";
				finishedCompetitors[i] = false;
			}
		}
		FinalRound(char* stringToParce, char parcer) {
			roundSize = ProtocolStringParser::getNumberOfFields(stringToParce, parcer);
			LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(stringToParce) + gcnew String("\" size is ") + roundSize.ToString());
			numbers = new char*[roundSize];
			for(int i = 0;i<roundSize;i++) {
				numbers[i] = ProtocolStringParser::getFieldByNumber(stringToParce,i,parcer);
			}
			filledNumbers = true;
			checkRoundDoubleNumbers(stringToParce);
		}
		void checkRoundDoubleNumbers(char* stringToParce) {
			for(int i = 0;i<roundSize;i++) {
				for(int j = i+1;j<roundSize;j++) {
					if(strcmp(numbers[i],numbers[j]) == 0){
						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Double numbers in string:") + gcnew String(stringToParce));
						filledNumbers = false;
						return;
					}
				}
			}
		}

		bool isThisResultsOfRound(FinalRound* finalRoundToCheck) {
			for(int i = 0;i<finalRoundToCheck->roundSize;i++) {
				bool numberFound = false;
				for(int j = 0;j<roundSize;j++) {
					if(strcmp(numbers[j],
						finalRoundToCheck->numbers[i]) == 0) {
						numberFound = true;
					}
				}
				if(!numberFound) {
					return false;
				}
			}
			return true;
		}

		void setValuesInRound(FinalRound* finalRoundResult) {
			char** tempValues = new char*[roundSize - finalRoundResult->roundSize];
			int counter = 0;
			for(int i = 0;i<roundSize;i++) {
				bool finishedThis = false;
				for(int j = 0;j<finalRoundResult->roundSize;j++) {
					if(strcmp(numbers[i],finalRoundResult->numbers[j])==0){
						finishedThis = true;
						break;
					}
				}
				if(!finishedThis) {
					tempValues[counter] = numbers[i];
					counter++;
				}

			}
			for(int i = 0;i<finalRoundResult->roundSize;i++) {
				numbers[i] = finalRoundResult->numbers[i];
				finishedCompetitors[i] = true;
			}
			for(int i = finalRoundResult->roundSize;i<roundSize;i++) {
				numbers[i] = tempValues[i-finalRoundResult->roundSize];
				finishedCompetitors[i] = false;
			}
			filledNumbers = true;
			filledResults = true;
		}

		void setValuesInRound(char* stringToParce, char parcer) {
			LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("setValuesInRound(char* stringToParce, char parcer)"));
			int inputRoundSize = ProtocolStringParser::getNumberOfFields(stringToParce, parcer);
			if(roundSize != inputRoundSize) {
				LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Wrong number of fields in string \"") +
					gcnew String(stringToParce) + gcnew String("\" should be:") + roundSize.ToString());
				filledNumbers = false;
				return;
			}
			for(int i = 0;i<roundSize;i++) {
				numbers[i] = ProtocolStringParser::getFieldByNumber(stringToParce,i,parcer);
			}
			filledNumbers = true;
			filledResults = true;
			checkRoundDoubleNumbers(stringToParce);
			LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("setValuesInRound(char* stringToParce, char parcer)"));
		}
	};

	class GroupEliminator {
	public:
		char* groupID;
		FinalRound* bigFinal;
		FinalRound* smallFinal;
		int numberOfCompetitorsInRound;
		double eliminationCoefficient;
		int numberOfRounds;
		GroupEliminator(char* stringToParce, char parcer,double eliminationCoeff) {
			eliminationCoefficient = eliminationCoeff;
			if(ProtocolStringParser::getNumberOfFields(stringToParce, parcer) < 3) {
				LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Wrong number of fields in group decription(should be 3):") + gcnew String(stringToParce));
				groupID = "Broken group info format";
				numberOfCompetitorsInRound = 8;
				numberOfRounds = 4;
			} else {
				groupID = ProtocolStringParser::getFieldByNumber(stringToParce,0,parcer);
				numberOfCompetitorsInRound = ProtocolStringParser::getIntByString(ProtocolStringParser::getFieldByNumber(stringToParce,1,parcer));
				numberOfRounds = ProtocolStringParser::getIntByString(ProtocolStringParser::getFieldByNumber(stringToParce,2,parcer));
			}
			smallFinal = new FinalRound(numberOfCompetitorsInRound);
			for(int i = 0;i< numberOfCompetitorsInRound;i++) {
				smallFinal->previousPlaces[i] = numberOfCompetitorsInRound + i + 1;
			}
			bigFinal = new FinalRound(numberOfCompetitorsInRound);
			bigFinal = recursiveCreateRounds(numberOfRounds, bigFinal);
//			for(int i = 0;i< numberOfCompetitorsInRound;i++) {
//				LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("blabla2 ") + bigFinal->previousPlaces[i].ToString());
//			}
		}
	private: FinalRound* recursiveCreateRounds(int numberOfRoundsCurrent, FinalRound* roundToCalculate) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("recursiveCreateRounds(int numberOfRoundsCurrent)"));
				 FinalRound* returnValueRound = roundToCalculate;
				 if(numberOfRoundsCurrent == numberOfRounds) {
		 			for(int i = 0;i< numberOfCompetitorsInRound;i++) {
						returnValueRound->previousPlaces[i] = i + 1;
//						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("blabla0 ") + returnValueRound->previousPlaces[i].ToString());
					}
				 }
				 if(numberOfRoundsCurrent > 0) {
					 returnValueRound->previousRounds = new FinalRound*[2];
					 for(int i = 0;i<2;i++) {
						 returnValueRound->previousRounds[i] = new FinalRound(numberOfCompetitorsInRound);
						 switch(numberOfCompetitorsInRound) {
							 case 2:
								 returnValueRound->previousRounds[i]->previousPlaces[0] = 
									 returnValueRound->previousPlaces[i];
								 returnValueRound->previousRounds[i]->previousPlaces[1] = 
									 pow(eliminationCoefficient,numberOfRounds-numberOfRoundsCurrent+1)*numberOfCompetitorsInRound + 1 - 
									 returnValueRound->previousPlaces[i];
								 break;
							 case 4:
								 returnValueRound->previousRounds[i]->previousPlaces[0] = 
									 returnValueRound->previousPlaces[i];
								 returnValueRound->previousRounds[i]->previousPlaces[1] = 
									 returnValueRound->previousPlaces[3-i];

								 returnValueRound->previousRounds[i]->previousPlaces[2] = 
									 pow(eliminationCoefficient,numberOfRounds-numberOfRoundsCurrent+1)*numberOfCompetitorsInRound + 1 - 
									 returnValueRound->previousPlaces[3-i];
								 returnValueRound->previousRounds[i]->previousPlaces[3] = 
									 pow(eliminationCoefficient,numberOfRounds-numberOfRoundsCurrent+1)*numberOfCompetitorsInRound + 1 - 
									 returnValueRound->previousPlaces[i];
								 break;
							 default:
								 throw (gcnew String(groupID) + gcnew String(" - Number of competitors in round should be one of values (2,4), but it is:" ) + numberOfCompetitorsInRound.ToString());
								 break;
						 }
						 returnValueRound->previousRounds[i] = recursiveCreateRounds(numberOfRoundsCurrent-1, returnValueRound->previousRounds[i]);

					 }
				 }
/*						 for(int asdf = 0;asdf< numberOfCompetitorsInRound;asdf++) {
							 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,returnValueRound->previousPlaces[asdf].ToString() + gcnew String(" qwerasdf"));
						 }*/
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("recursiveCreateRounds(int numberOfRoundsCurrent)"));
				 return returnValueRound;
			 }
	public: void addCompetitor(char* competitorID, double competitorPlace)
			 {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("void addCompetitor(char* competitorID, double competitorPlace)"));
				 if(competitorPlace - 1 < pow(eliminationCoefficient,numberOfRounds-1)*numberOfCompetitorsInRound) {
					 for(int roundsCounter = 0; roundsCounter < pow(eliminationCoefficient,numberOfRounds-1); roundsCounter++) {
						 FinalRound* currentRound = getFinalByStageAndNumber(0,roundsCounter);
						 for(int competitorsCounter = 0;competitorsCounter < numberOfCompetitorsInRound;competitorsCounter++) {
							 if(currentRound->previousPlaces[competitorsCounter] == competitorPlace) {
								 if(strcmp(currentRound->numbers[competitorsCounter],"")!=0) {
									 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Number ") + gcnew String(competitorID) +
										 gcnew String("  has the same place in start protocol as ") + gcnew String(currentRound->numbers[competitorsCounter]));
								 }
								 currentRound->numbers[competitorsCounter] = competitorID;
								 currentRound->filledNumbers = true;
								 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("void addCompetitor(char* competitorID, double competitorPlace)"));
								 return;
							 }
						 }
					 }
				 }
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("void addCompetitor(char* competitorID, double competitorPlace)"));
			 }

	public: FinalRound* getFinalByStageAndNumber(int finalStep,int finalNumber) {
				if(finalStep<0||finalStep>=numberOfRounds) {
					LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,finalStep.ToString() + gcnew String(" stage is out of bounds. Max=") + numberOfRounds.ToString());
					return new FinalRound(numberOfCompetitorsInRound);
				}
				if((finalNumber == 1)&&(finalStep == numberOfRounds-1)) {
					return smallFinal;
				} else {
					if((finalNumber+1 > pow(eliminationCoefficient,numberOfRounds-finalStep-1)) || (finalNumber < 0)) {
						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Final step number can not be found step=") + 
							finalStep.ToString() + gcnew String(" stage=") + finalNumber.ToString() + gcnew String(" from number of steps=") + numberOfRounds.ToString() +
							gcnew String(" it should be between") + pow(eliminationCoefficient,numberOfRounds-finalStep-1).ToString() +
							gcnew String(" and 0"));
						return new FinalRound(numberOfCompetitorsInRound);
					} else {
						FinalRound* returnValue = bigFinal;
						int tempFinalNumber = finalNumber;
						for(int stepCounter = numberOfRounds-1;stepCounter > finalStep;stepCounter--) {
							int tempGo = tempFinalNumber/pow(eliminationCoefficient,stepCounter-finalStep-1);
							tempFinalNumber = tempFinalNumber-tempGo*pow(eliminationCoefficient,stepCounter-finalStep-1);
							returnValue = returnValue->previousRounds[tempGo];
						}
						return returnValue;

					}
				}

		}
	};

	class GroupStartElement {
		 public:
			 int place;
			 double seconds;
			 char* groupID;
			 GroupStartElement() {
				 place = 1;
				 seconds = 0;
				 groupID = new char();
			 }
			 ~GroupStartElement() {
				 delete groupID;
			 }

			 GroupStartElement(char* grId, double sec) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter constructor GroupStartElement(char* grId, double sec) with parameters \"") + gcnew String(grId) + gcnew String("\", \"") + sec.ToString() + gcnew String("\""));
				 place = 1;
				 groupID = new char[strlen(grId) + 1];
				 strcpy(groupID,(const char*)grId);
				 seconds = sec;
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit constructor GroupStartElement(char* grId, double sec) with parameters \"") + gcnew String(grId) + gcnew String("\", \"") + sec.ToString() + gcnew String("\""));
			 }
			 GroupStartElement(char* stringToParse, char parser) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter constructor GroupStartElement(char* stringToParse, char parser) with parameters \"") + gcnew String(stringToParse) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 place = 1;
				 groupID = ProtocolStringParser::getFieldByNumber(stringToParse,0,parser);
				 seconds = ProtocolStringParser::getSecondsByTime(ProtocolStringParser::getFieldByNumber(stringToParse,1,parser));
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit constructor GroupStartElement(char* stringToParse, char parser) with parameters \"") + gcnew String(stringToParse) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
			 }
		 };
		 public class FinishCompetitorElement {
		 public:
			 char* competitorID;
			 double seconds;
			 char* action;
			 int penalty;
			 FinishCompetitorElement (char* stringToParse, char parser) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter constructor FinishCompetitorElement (char* stringToParse, char parser) with parameters \"") + gcnew String(stringToParse) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
				 competitorID = ProtocolStringParser::getFieldByNumber(stringToParse,0,parser);
				 seconds = ProtocolStringParser::getSecondsByTime(ProtocolStringParser::getFieldByNumber(stringToParse,1,parser));
				 action = ProtocolStringParser::getFieldByNumber(stringToParse,2,parser);
				 if(ProtocolStringParser::getNumberOfFields(stringToParse,parser)>3) {
					 penalty = ProtocolStringParser::getIntByString(ProtocolStringParser::getFieldByNumber(stringToParse,3,parser));
				 }
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit constructor FinishCompetitorElement (char* stringToParse, char parser) with parameters \"") + gcnew String(stringToParse) + gcnew String("\", \"") + gcnew String(&parser) + gcnew String("\""));
			 }
			 FinishCompetitorElement () {
				 competitorID = new char();
				 seconds = 0.0;
				 action = new char();
				 penalty = 0;
			 }
			 ~FinishCompetitorElement () {
				 delete competitorID;
				 delete action;
			 }
		 };
		 public class IntermediateCrosses {
		 public:
			 double* segmentCrosses; //absolute time of segment cross
			 double* segmentFinishes; //times for segment finish from lap start
			 double* segmentTimes; // time for segment
			 ~IntermediateCrosses() {
				 delete segmentCrosses;
				 delete segmentFinishes;
				 delete segmentTimes;
			 }
			 IntermediateCrosses(int numberOfPoints) {
				 segmentCrosses = new double[numberOfPoints];
				 segmentFinishes = new double[numberOfPoints];
				 segmentTimes = new double[numberOfPoints];
				 for(int i = 0;i< numberOfPoints;i++) {
					 segmentCrosses[i] = -1;
					 segmentFinishes[i] = -1;
					 segmentTimes[i] = -1;
				 }
			 }
		 };


		 public class FinishProtocolElement {
		 public:
			 bool sorted;
			 char* attemptsRegexp;
			 char* competitorID;
			 int competitorNumber;
			 char* groupID;
			 char* competitorName;
			 char* competitorYearOfBirth;
			 char* competitorTeam;
			 char* competitorCity;
			 char* competitorAdditionalInfo;
			 int stagesNumber;
			 int numberOfLaps;
			 int numberOfLapsFinished;
			 int* lapFinishNumbers;
			 double* lapTimes;
			 double* finishLapTimes;
			 double* crossLineTimes;
			 IntermediateCrosses** controlPoints;
			 bool finished;
			 bool disqualified;
			 double startDelay;
			 double totalTime;
			 bool totalTimeCalculated;
			 int numberOfLapsToResult;
			 bool numberOfLapsToResultCalculated;
			 int numberOfAttempts;
			 bool numberOfAttemptsCalculated;
			 int numberOfSuccessfullyFinishedTries;
			 bool numberOfSuccessfullyFinishedTriesCalculated;
			 bool stringChecked;
			 char** lapPenaltyComment;
			 ~FinishProtocolElement() {
				delete attemptsRegexp;
				delete competitorID;
				delete groupID;
				delete competitorName;
				delete competitorYearOfBirth;
				delete competitorTeam;
				delete competitorCity;
				delete competitorAdditionalInfo;
				delete lapTimes;
				delete finishLapTimes;
				delete crossLineTimes;
				delete controlPoints;
				delete lapFinishNumbers;
			 }
			 FinishProtocolElement(StartProtocolElement* startElement,bool defaultFinished, bool defaultDisqualified, int numberOfPoints) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION, gcnew String("Enter constructor FinishProtocolElement(StartProtocolElement* startElement,bool defaultFinished, bool defaultDisqualified) with startElementId \""));
				 if(startElement->numberOfLaps!=-1) {
					numberOfLaps = startElement->numberOfLaps;
				 } else {
					 numberOfLaps = 1000;
				 }
				 attemptsRegexp = "([0-9]+):([0-9]+)+(,([0-9]+)+)*";
				 lapTimes = new double[numberOfLaps];
				 finishLapTimes = new double[numberOfLaps];
				 crossLineTimes = new double[numberOfLaps+1];
				 lapFinishNumbers = new int[numberOfLaps];
				 competitorName = startElement->competitorName;
				 controlPoints = new IntermediateCrosses*[numberOfLaps];
				 lapPenaltyComment = new char*[numberOfLaps];
				 for(int i = 0;i<numberOfLaps;i++) {
					 controlPoints[i] = new IntermediateCrosses(numberOfPoints);
					 lapPenaltyComment[i] = new char[LoggerSTC::numberOfCharsInString];
					 lapPenaltyComment[i][0]=0;
				 }
				 competitorID = startElement->competitorID;
				 groupID = startElement->groupID;
				 competitorYearOfBirth = startElement->competitorYearOfBirth;
				 competitorTeam = startElement->competitorTeam;
				 competitorCity = startElement->competitorCity;
				 competitorAdditionalInfo = startElement->competitorAdditionalInfo;
				 if(startElement->stagesNumber!=-1) {
					stagesNumber = startElement->stagesNumber;
				 } else {
					 stagesNumber = 1;
				 }
				 if(stagesNumber != 1) {
					 competitorNumber = ProtocolStringParser::getIntByString(competitorID);
				 }
				 startDelay = startElement->startDelay;
				 numberOfLapsFinished = 0;
				 finished = defaultFinished;
				 disqualified = defaultDisqualified;
				 sorted = false;
				 totalTimeCalculated = false;
				 numberOfLapsToResultCalculated = false;
				 numberOfAttemptsCalculated = false;
				 numberOfSuccessfullyFinishedTriesCalculated = false;
				 stringChecked = false;
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION, gcnew String("Exit constructor FinishProtocolElement(StartProtocolElement* startElement,bool defaultFinished, bool defaultDisqualified) with startElementId \""));
			 }
		 private: bool checkAttemptsString() {
					  if(stringChecked) {
						  return true;
					  }
					 Regex^ myRegexp = gcnew Regex(gcnew String(attemptsRegexp));
					 if(!myRegexp->IsMatch(gcnew String(competitorAdditionalInfo))) {
						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Competitor attempts string (additional info) should have format 'number of best attempts':'first attempt','second attempts'...etc. Broken for competitor ") + gcnew String(competitorID) +
							gcnew String(" value is: ") + gcnew String(competitorAdditionalInfo));
						return false;
					 }
						LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String("[OK] Competitor attempts string (additional info) should have format 'number of best attempts':'first attempt','second attempts'...etc. ") + gcnew String(competitorID) +
							gcnew String(" value is: ") + gcnew String(competitorAdditionalInfo));
						stringChecked = true;
					 return true;
				 }
		 private: int getNumberOfLapsToResult(bool needToRecalculate) {
					  if(!needToRecalculate && numberOfLapsToResultCalculated) {
						  return numberOfLapsToResult;
					  }
					 if(!checkAttemptsString()) {
						return 0;
					 }
					 Regex^ myRegexp = gcnew Regex(gcnew String(attemptsRegexp));
					 String^ result = myRegexp->Replace(gcnew String(competitorAdditionalInfo),gcnew String("$1"));
					 myRegexp->Split(gcnew String(competitorAdditionalInfo))->Length;
					 numberOfLapsToResult = ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(result));
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" for this competitor number of laps that will be added to result is ") + 
						 gcnew String((gcnew Int32(numberOfLapsToResultCalculated))->ToString()));
					 numberOfLapsToResultCalculated  = true;
					 return numberOfLapsToResult;
				 }

		 public: int getNumberOfAttempts(bool needToRecalculate) {
					  if(!needToRecalculate && numberOfAttemptsCalculated) {
						  return numberOfAttempts;
					  }
					 if(!checkAttemptsString()) {
						 return 0;
					 }
					 numberOfAttempts = 1;
					 String^ additionalInfo = gcnew String(competitorAdditionalInfo);
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, additionalInfo);

					 Regex ^firstNumber = gcnew Regex(gcnew String("([0-9]+):([0-9,]+)"));
					 Regex ^otherNumbers = gcnew Regex(gcnew String("([0-9]+),([0-9,]+)"));

					 additionalInfo = firstNumber->Replace(additionalInfo, gcnew String("$2"));
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, additionalInfo);
					 while(otherNumbers->IsMatch(additionalInfo)) {
						 additionalInfo = otherNumbers->Replace(additionalInfo, gcnew String("$2"));
						 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, additionalInfo);
						 numberOfAttempts++;
						 if(numberOfAttempts>1000) {
							 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Something went wrong: infinite cycle"));
							 numberOfAttempts = 0;
							 return 0;
						 }
					 }
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" for this competitor number of laps that will be added to result is ") + 
						 gcnew String((gcnew Int32(numberOfAttempts))->ToString()));
					 numberOfAttemptsCalculated = true;
					 return numberOfAttempts;
				 }

		 public: int getAttemptByNumber(int i,  bool needToRecalculate) {
					 if(!checkAttemptsString() ||  getNumberOfAttempts(needToRecalculate) < i) {
						 return 0;
					 }
					 String^ additionalInfo = gcnew String(competitorAdditionalInfo);
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, additionalInfo);

					 Regex ^firstNumber = gcnew Regex(gcnew String("([0-9]+):([0-9,]+)"));
					 Regex ^otherNumbers = gcnew Regex(gcnew String("([0-9]+),([0-9,]+)"));

					 additionalInfo = firstNumber->Replace(additionalInfo, gcnew String("$2"));
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, additionalInfo);
					 for(int j=1;j<i;j++) {
						 additionalInfo = otherNumbers->Replace(additionalInfo, gcnew String("$2"));
						 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, additionalInfo);
					 }
					 Regex^ myRegexp = gcnew Regex(gcnew String("([0-9]+)([,]*)([0-9,]*)"));
					 String^ result = myRegexp->Replace(additionalInfo,gcnew String("$1"));
					 myRegexp->Split(gcnew String(competitorAdditionalInfo))->Length;
					 int res = ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(result));
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" for this competitor lap ") + 
						 gcnew String((gcnew Int32(res))->ToString()) + gcnew String(" will be setted as result number ") +
						 gcnew String((gcnew Int32(i))->ToString()));
					 return res;
					 
				 }
				 public: double getTimeDifference(FinishProtocolElement* leader, bool needToRecalculate) {
							 return getTotalTime(needToRecalculate) - leader->getTotalTime(getNumberOfSuccessfullyFinishedTries(needToRecalculate), needToRecalculate);
						 }
		 public: double getTotalTime(bool needToRecalculate) {
					 if(!needToRecalculate && totalTimeCalculated) {
						 return totalTime;
					 }
					 totalTime = getTotalTime(getNumberOfLapsToResult(needToRecalculate), needToRecalculate);
					 totalTimeCalculated = true;
					 return totalTime;
				 }
		 public: double getTotalTime(int numberOfMaximumTries, bool needToRecalculate) {
					 if(!checkAttemptsString()) {
						 return 0.0;
					 }
					 int numberOfTries = Math::Min(getNumberOfLapsToResult(needToRecalculate), numberOfMaximumTries);
					 double* bestResults = new double[numberOfTries];
					 double result = 0;
					 for(int i = 0;i<numberOfTries;i++) {
						 bestResults[i] = Double::MaxValue;	
					 }
					 for(int i = 1; i <=getNumberOfAttempts(needToRecalculate); i++) {
						 int lapNumber = getAttemptByNumber(i, needToRecalculate);
//						 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" - competitor: lapNumber,getNumberOfAttempts(),i ") + 
//							 gcnew String((gcnew Int32(lapNumber))->ToString()) + gcnew String(", ") +
//							 gcnew String((gcnew Int32(getNumberOfAttempts()))->ToString()) + gcnew String(", ") +
//							 gcnew String((gcnew Int32(i))->ToString()));
						 if(lapNumber<=numberOfLapsFinished) {
							 double attemptResult=crossLineTimes[lapNumber]-crossLineTimes[lapNumber-1];
//							 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" - competitor: crossLineTimes[lapNumber],crossLineTimes[lapNumber-1],attemptResult ") + 
//								 gcnew String((gcnew Double(crossLineTimes[lapNumber]))->ToString()) + gcnew String(", ") +
//								 gcnew String((gcnew Double(crossLineTimes[lapNumber-1]))->ToString()) + gcnew String(", ") +
//								 gcnew String((gcnew Double(attemptResult))->ToString()));
							 for(int j = 0;j<numberOfTries;j++) {
//								 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" - competitor: j,bestResults[j] ") + 
//									 gcnew String((gcnew Int32(j))->ToString()) + gcnew String(", ") +
//									 gcnew String((gcnew Double(bestResults[j]))->ToString()));
								 if(bestResults[j]>attemptResult) {
									 int worstAttemptNumber = 0;
									 worstAttemptNumber = 0;
									 for(int k = 1;k<numberOfTries;k++) {
//										 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" - competitor: k,worstAttemptNumber, bestResults[k], bestResults[worstAttemptNumber]") + 
//											 gcnew String((gcnew Int32(k))->ToString()) + gcnew String(", ") +
//											 gcnew String((gcnew Int32(worstAttemptNumber))->ToString()) + gcnew String(", ") +
//											 gcnew String((gcnew Double(bestResults[k]))->ToString()) + gcnew String(", ") +
//											 gcnew String((gcnew Double(bestResults[worstAttemptNumber]))->ToString()));
										 if(bestResults[k] > bestResults[worstAttemptNumber]) {
											 worstAttemptNumber = k;
										 }
									 }
//									 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" - competitor: worstAttemptNumber, attemptResult, bestResults[worstAttemptNumber]") + 
//										 gcnew String((gcnew Int32(worstAttemptNumber))->ToString()) + gcnew String(", ") +
//										 gcnew String((gcnew Double(attemptResult))->ToString()) + gcnew String(", ") +
//										 gcnew String((gcnew Double(bestResults[worstAttemptNumber]))->ToString()));
									 bestResults[worstAttemptNumber] = attemptResult;
									 break;
								 }
							 }
						 }
					 }
					 for(int i = 0;i<numberOfTries;i++) {
						 if(bestResults[i]!=Double::MaxValue) {
							 result += bestResults[i];
						 }
					 }
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" for this competitor result is ") + 
						 gcnew String((gcnew Double(result))->ToString()));
					 return result;
				 }

		 public: int getNumberOfSuccessfullyFinishedTries(bool needToRecalculate) {
					 if(!needToRecalculate && numberOfSuccessfullyFinishedTriesCalculated) {
						 return numberOfSuccessfullyFinishedTries;
					 }
					 if(!checkAttemptsString()) {
						return 0;
					 }
					 int result = 0;
					 for(int i = 1; i <=getNumberOfAttempts(needToRecalculate); i++) {
						 if(getAttemptByNumber(i, needToRecalculate)<=numberOfLapsFinished) {
							 result++;
						 }
					 }
					 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String(competitorID) + gcnew String(" for this competitor number of successfully finished laps is ") + 
						 gcnew String((gcnew Int32(result))->ToString()));
					 numberOfSuccessfullyFinishedTries = Math::Min(result, getNumberOfLapsToResult(needToRecalculate));
					 numberOfSuccessfullyFinishedTriesCalculated = true;
					 return numberOfSuccessfullyFinishedTries;
				 }

		 public: String^ ToString(String^ fieldsDeliminer, int competitorPlace) {
					 return gcnew String(competitorID) + fieldsDeliminer + 
						 gcnew String(competitorName) + fieldsDeliminer + 
						 gcnew String(groupID) + fieldsDeliminer + 
						 numberOfLaps.ToString() + fieldsDeliminer + 
						 stagesNumber.ToString() + fieldsDeliminer + 
						 gcnew String(competitorYearOfBirth) + fieldsDeliminer + 
						 gcnew String(competitorTeam) + fieldsDeliminer + 
						 gcnew String(competitorCity) + fieldsDeliminer + 
						 gcnew String(competitorAdditionalInfo) + fieldsDeliminer + 
						 competitorPlace.ToString() + fieldsDeliminer;

				 }


		 };
		 class RelayTeam{ 
		 public:
			 FinishProtocolElement* teamMembers;
			 char* teamName;
			 int numberOfStages;
			 int sumNumberOfLaps;
			 double finishTime;
			 RelayTeam() {
				 teamName = "Default Name";
				 numberOfStages = 1;
				 sumNumberOfLaps = 1;
				 finishTime = 0;
			 }
		 };
}