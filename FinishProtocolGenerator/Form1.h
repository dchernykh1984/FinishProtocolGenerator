#pragma once
#include "finishProtocolStructures.h"
#include <time.h>


namespace FinishProtocolGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Text;
	using namespace System::Threading;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>


	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		static String^ raceTypeMassOrSplitted = gcnew String("Mass Start or Splited Start");
		static String^ raceTypeMassOrSplittedSpiridonov = gcnew String("Mass Start or Splitted Start with Spiridonov's coefficients");
		static String^ raceTypeEliminatorQualification = gcnew String("Eliminator Qualification");
		static String^ raceTypeEliminatorFinals = gcnew String("Eliminator Finals");
		static String^ raceTypeCustomStart = gcnew String("Custom Start");
	private: System::Windows::Forms::Label^  labelLapName;
	private: System::Windows::Forms::TextBox^  textBoxLapName;
	private: System::Windows::Forms::Label^  labelLapAdditional;
	private: System::Windows::Forms::TextBox^  textBoxLapAdditionalInfo;
	private: static bool skipFirstLapVariable = false;
	private: static bool generateTextFinishProtocolVariable = false;
	private: static bool isEliminatorFinalsVariable = false;
	private: static bool useSpiridonovCoefficientsVariable = false;
	private: static bool isNumberOfTriesVariable = false;

			 static String^ raceTypeNumberOfTries = gcnew String("Number of Tries");
private: System::Void comboBoxRaceType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 skipFirstLapVariable = comboBoxRaceType->Text->Equals(raceTypeCustomStart);
			 generateTextFinishProtocolVariable = comboBoxRaceType->Text->Equals(raceTypeEliminatorQualification);
			 isEliminatorFinalsVariable = comboBoxRaceType->Text->Equals(raceTypeEliminatorFinals);
			 useSpiridonovCoefficientsVariable = comboBoxRaceType->Text->Equals(raceTypeMassOrSplittedSpiridonov);
			 isNumberOfTriesVariable = comboBoxRaceType->Text->Equals(raceTypeNumberOfTries);
		 }
		 private: bool skipFirstLap() {
					  return skipFirstLapVariable || isNumberOfTries();
				  }
		 private: bool generateTextFinishProtocol() {
					  return generateTextFinishProtocolVariable;
				  }
		 private: bool isEliminatorFinals() {
					  return isEliminatorFinalsVariable;
				  }
		 private: bool useSpiridonovCoefficients() {
					  return useSpiridonovCoefficientsVariable;
				  }
				  bool isNumberOfTries() {
					  return isNumberOfTriesVariable;
				  }

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		static bool isInProgress;
		static int numberOfPoints = 0;
		static const int arraysVolume = 500000;
		static const char currentParser = '#';
	FILE* startProtocolFile;
	FILE* finishTimeFile;
	FILE* groupsStartTimeFile;
	FILE* groupProtocolFile;
	FILE* groupProtocolFileText;
	FILE* absoluteProtocolFile;
	FILE* remoteTimeFile;
	FILE* startCheckListFile;
	FinishCompetitorElement** startCheckList;
	FinishCompetitorElement** finishCompetitorList;
	FinalRound** finalRoundsList;
	FinishCompetitorElement*** remotePointsList;
	StartProtocolElement** startProtocolList;
	GroupStartElement** groupStartList;
	GroupEliminator** groupEliminatorList;
	FinishProtocolElement** finishProtocolList;
	FinishProtocolElement** finishProtocolListSorted;
	int numberOfCompetitorElements;
	int *numberOfRemoteElements;
	int numberOfStartChecks;
	int numberOfEliminatorGroups;
	int numberOfFinalRounds;

	static int columnsNumber = 1;
	static int rowsNumber = 1;
	static bool downloadStart = false;
	static bool downloadGroups = false;
	static bool downloadResults = false;
	static bool downloadRemote = false;
	static String^ downloadReplace = gcnew String("Download");
	static String^ downloadMerge = gcnew String("Merge");
	static String^ downloadMergeRemove = gcnew String("Merge+Remove");
	static String^ checkListFileName = gcnew String("temp\\results_start.txt");

	 String^ tableStyle;
	 String^ topLineStyle;
	 String^ evenLineStyle;
	 String^ oddLineStyle;
	 String^ groupNameStyle;
	 String^ additionalTextTopStyle;
	 String^ additionalTextStyle;
	 String^ topTextStyle;
	 String^ additionalInfoTopStyle;
	 String^ additionalInfoStyle;
	 String^ commonStyleText;

	int numberOfStartProtocolElements;
	int numberOfGroups;
	int numberOfFinishProtocolElements;
	private: System::Windows::Forms::Button^  buttonStartProtocol;
	private: System::Windows::Forms::Button^  buttonGroupTime;
	private: System::Windows::Forms::Button^  buttonFinishTime;
	private: System::Windows::Forms::Button^  buttonGroupsProtocol;



	protected: 

	protected: 




	private: System::Windows::Forms::TextBox^  textBoxStartProtocol;
	private: System::Windows::Forms::TextBox^  textBoxGroupTime;
	private: System::Windows::Forms::TextBox^  textBoxFinishTime;
	private: System::Windows::Forms::TextBox^  textBoxGroupsProtocol;













	private: System::Windows::Forms::Button^  buttonGenerateProtocol;

	private: System::Windows::Forms::TextBox^  textBoAbsoluteProtocol;
	private: System::Windows::Forms::Button^  buttonAbsoluteProtocol;
	private: System::Windows::Forms::CheckBox^  checkBoxDisableDNF;
	private: System::Windows::Forms::CheckBox^  checkBoxDisableDSQ;
	private: System::Windows::Forms::CheckBox^  checkBoxUseFileLogger;

	private: System::Windows::Forms::ListBox^  listBoxLogger;
	private: System::Windows::Forms::Label^  labelLoggerInfo;
	private: System::Windows::Forms::TextBox^  textBoxLogSearch;
	private: System::Windows::Forms::Button^  buttonLogSearch;
	private: System::Windows::Forms::Label^  labelLogSearch;

	private: System::Windows::Forms::Label^  labelRaceName;
	private: System::Windows::Forms::Label^  labelRaceDate;
	private: System::Windows::Forms::Label^  labelRacePlace;
	private: System::Windows::Forms::Label^  labelWeather;



	private: System::Windows::Forms::TextBox^  textBoxRaceName;
	private: System::Windows::Forms::TextBox^  textBoxRaceDate;
	private: System::Windows::Forms::TextBox^  textBoxRacePlace;
	private: System::Windows::Forms::TextBox^  textBoxWeather;

	private: System::Windows::Forms::TextBox^  textBoxMainReferee;



	private: System::Windows::Forms::TextBox^  textBoxAdditionalReferee;

	private: System::Windows::Forms::Label^  labelMainReferee;
	private: System::Windows::Forms::Label^  labelAdditionalReferee;
private: System::Windows::Forms::Label^  labelOrganizator;
private: System::Windows::Forms::TextBox^  textBoxOrganizator;
private: System::Windows::Forms::Label^  labelTrackConditions;
private: System::Windows::Forms::TextBox^  textBoxTrackConditions;
private: System::Windows::Forms::Label^  labelMinimalTimeForLap;
private: System::Windows::Forms::TextBox^  textBoxMinimalTimeForLap;
private: System::Windows::Forms::CheckBox^  checkBoxUseInterfaceLogger;
private: System::Windows::Forms::Button^  buttonLoadRaceInfoData;







private: System::Windows::Forms::TextBox^  textBoxNumberOfSignsAfterPoint;

private: System::Windows::Forms::Label^  labelNumberOfSignsAfterPoint;
private: System::Windows::Forms::CheckBox^  checkBoxShowID;
private: System::Windows::Forms::CheckBox^  checkBoxShowName;
private: System::Windows::Forms::CheckBox^  checkBoxShowAge;
private: System::Windows::Forms::CheckBox^  checkBoxShowTeam;
private: System::Windows::Forms::CheckBox^  checkBoxShowCity;
private: System::Windows::Forms::CheckBox^  checkBoxShowLapTimes;
private: System::Windows::Forms::CheckBox^  checkBoxShowFinishTime;
private: System::Windows::Forms::CheckBox^  checkBoxShowGroup;
private: System::Windows::Forms::CheckBox^  checkBoxShowPlace;
private: System::Windows::Forms::CheckBox^  checkBoxStratch;
private: System::Windows::Forms::CheckBox^  checkBoxPrintDNF;
private: System::Windows::Forms::TextBox^  textBoxID;
private: System::Windows::Forms::TextBox^  textBoxName;
private: System::Windows::Forms::TextBox^  textBoxAge;
private: System::Windows::Forms::TextBox^  textBoxCity;

private: System::Windows::Forms::TextBox^  textBoxPlace;






private: System::Windows::Forms::TextBox^  textBoxTeam;

private: System::Windows::Forms::TextBox^  textBoxGroup;

private: System::Windows::Forms::CheckBox^  checkBoxLapFinnish;
private: System::Windows::Forms::CheckBox^  checkBoxTimeDifference;
private: System::Windows::Forms::TextBox^  textBoxReferee;
private: System::Windows::Forms::TextBox^  textBoxSecretary;


private: System::Windows::Forms::Label^  labelRefereeText;
private: System::Windows::Forms::Label^  labelSecretary;
private: System::Windows::Forms::CheckBox^  checkBoxPrintDNS;
private: System::Windows::Forms::CheckBox^  checkBoxPrintDSQ;
private: System::Windows::Forms::CheckBox^  checkBoxErrAndWrnOnly;
private: System::Windows::Forms::CheckBox^  checkBoxAdditionalInfo;
private: System::Windows::Forms::TextBox^  textBoxAdditonalInfo;
private: System::Windows::Forms::Button^  buttonRefreshTimeSubmit;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBoxRefreshTime;
private: System::Windows::Forms::CheckBox^  checkBoxRefresh;
private: System::Windows::Forms::Timer^  timerRefresh;
private: System::Windows::Forms::Button^  buttonSaveRaceInfo;
private: System::Windows::Forms::CheckBox^  checkBoxTimeShift;
private: System::Windows::Forms::TextBox^  textBoxTimeShift;
private: System::Windows::Forms::CheckBox^  checkBoxButtons;
private: System::Windows::Forms::TextBox^  textBoxRemotePointsNumber;


private: System::Windows::Forms::TextBox^  textBoxRemotePoints;

private: System::Windows::Forms::Label^  labelRemotePoints;

private: System::Windows::Forms::Button^  buttonRemotePoints;
private: System::Windows::Forms::CheckBox^  checkBoxAllButtons;
private: System::Windows::Forms::CheckBox^  checkBoxUploadGroups;


private: System::Windows::Forms::TextBox^  textBoxFTPPath;
private: System::Windows::Forms::TextBox^  textBoxFTPLogin;
private: System::Windows::Forms::TextBox^  textBoxFTPPassword;


private: System::Windows::Forms::CheckBox^  checkBoxUploadAbsolute;






private: System::Windows::Forms::CheckBox^  checkBoxShowLoginPassword;
private: System::Windows::Forms::TextBox^  textBoxSponsor;

private: System::Windows::Forms::Label^  labelSponsor;

private: System::Windows::Forms::CheckBox^  checkBoxNumberOfFinishedLaps;
private: System::Windows::Forms::CheckBox^  checkBoxLapsDifference;

private: System::Windows::Forms::MaskedTextBox^  maskedTextBoxLapsDifference;
private: System::Windows::Forms::CheckBox^  checkBoxHideEmptyColumns;
private: System::Windows::Forms::Label^  labelStartList;
private: System::Windows::Forms::Label^  labelGroupsTimes;
private: System::Windows::Forms::Label^  labelResultTimes;






private: System::Windows::Forms::Label^  labelRemotePointsDownload;
private: System::Windows::Forms::ComboBox^  comboBoxStartListAction;
private: System::Windows::Forms::ComboBox^  comboBoxGroupsTimesAction;
private: System::Windows::Forms::ComboBox^  comboBoxResultTimesAction;
private: System::Windows::Forms::ComboBox^  comboBoxRemotePointsAction;
private: System::Windows::Forms::Label^  labelTimeLimit;
private: System::Windows::Forms::TextBox^  textBoxTimeLimit;

private: System::Windows::Forms::ComboBox^  comboBoxStartCheckList;
private: System::Windows::Forms::CheckBox^  checkBoxStartCheckList;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBoxStartRegistrationPeriod;
private: System::Windows::Forms::Label^  labelRegistrationPeriod;
private: System::Windows::Forms::Label^  labelBottom;
private: System::Windows::Forms::TextBox^  textBoxBottom;


private: System::Windows::Forms::CheckBox^  checkBoxMergeByID;
private: System::Windows::Forms::ComboBox^  comboBoxRaceType;



private: System::Windows::Forms::Label^  labelRaceType;

















private: System::ComponentModel::IContainer^  components;





























	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->buttonStartProtocol = (gcnew System::Windows::Forms::Button());
			this->buttonGroupTime = (gcnew System::Windows::Forms::Button());
			this->buttonFinishTime = (gcnew System::Windows::Forms::Button());
			this->buttonGroupsProtocol = (gcnew System::Windows::Forms::Button());
			this->textBoxStartProtocol = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGroupTime = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFinishTime = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGroupsProtocol = (gcnew System::Windows::Forms::TextBox());
			this->buttonGenerateProtocol = (gcnew System::Windows::Forms::Button());
			this->textBoAbsoluteProtocol = (gcnew System::Windows::Forms::TextBox());
			this->buttonAbsoluteProtocol = (gcnew System::Windows::Forms::Button());
			this->checkBoxDisableDNF = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxDisableDSQ = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxUseFileLogger = (gcnew System::Windows::Forms::CheckBox());
			this->listBoxLogger = (gcnew System::Windows::Forms::ListBox());
			this->labelLoggerInfo = (gcnew System::Windows::Forms::Label());
			this->textBoxLogSearch = (gcnew System::Windows::Forms::TextBox());
			this->buttonLogSearch = (gcnew System::Windows::Forms::Button());
			this->labelLogSearch = (gcnew System::Windows::Forms::Label());
			this->labelRaceName = (gcnew System::Windows::Forms::Label());
			this->labelRaceDate = (gcnew System::Windows::Forms::Label());
			this->labelRacePlace = (gcnew System::Windows::Forms::Label());
			this->labelWeather = (gcnew System::Windows::Forms::Label());
			this->textBoxRaceName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRaceDate = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRacePlace = (gcnew System::Windows::Forms::TextBox());
			this->textBoxWeather = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMainReferee = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAdditionalReferee = (gcnew System::Windows::Forms::TextBox());
			this->labelMainReferee = (gcnew System::Windows::Forms::Label());
			this->labelAdditionalReferee = (gcnew System::Windows::Forms::Label());
			this->labelOrganizator = (gcnew System::Windows::Forms::Label());
			this->textBoxOrganizator = (gcnew System::Windows::Forms::TextBox());
			this->labelTrackConditions = (gcnew System::Windows::Forms::Label());
			this->textBoxTrackConditions = (gcnew System::Windows::Forms::TextBox());
			this->labelMinimalTimeForLap = (gcnew System::Windows::Forms::Label());
			this->textBoxMinimalTimeForLap = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxUseInterfaceLogger = (gcnew System::Windows::Forms::CheckBox());
			this->buttonLoadRaceInfoData = (gcnew System::Windows::Forms::Button());
			this->textBoxNumberOfSignsAfterPoint = (gcnew System::Windows::Forms::TextBox());
			this->labelNumberOfSignsAfterPoint = (gcnew System::Windows::Forms::Label());
			this->checkBoxShowID = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowName = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowAge = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowTeam = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowCity = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowLapTimes = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowFinishTime = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowGroup = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowPlace = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxStratch = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxPrintDNF = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAge = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCity = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPlace = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTeam = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGroup = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxLapFinnish = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxTimeDifference = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxReferee = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSecretary = (gcnew System::Windows::Forms::TextBox());
			this->labelRefereeText = (gcnew System::Windows::Forms::Label());
			this->labelSecretary = (gcnew System::Windows::Forms::Label());
			this->checkBoxPrintDNS = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxPrintDSQ = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxErrAndWrnOnly = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxAdditionalInfo = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxAdditonalInfo = (gcnew System::Windows::Forms::TextBox());
			this->buttonRefreshTimeSubmit = (gcnew System::Windows::Forms::Button());
			this->maskedTextBoxRefreshTime = (gcnew System::Windows::Forms::MaskedTextBox());
			this->checkBoxRefresh = (gcnew System::Windows::Forms::CheckBox());
			this->timerRefresh = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonSaveRaceInfo = (gcnew System::Windows::Forms::Button());
			this->checkBoxTimeShift = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxTimeShift = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxButtons = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxRemotePointsNumber = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRemotePoints = (gcnew System::Windows::Forms::TextBox());
			this->labelRemotePoints = (gcnew System::Windows::Forms::Label());
			this->buttonRemotePoints = (gcnew System::Windows::Forms::Button());
			this->checkBoxAllButtons = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxUploadGroups = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxFTPPath = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFTPLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFTPPassword = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxUploadAbsolute = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowLoginPassword = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxSponsor = (gcnew System::Windows::Forms::TextBox());
			this->labelSponsor = (gcnew System::Windows::Forms::Label());
			this->checkBoxNumberOfFinishedLaps = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxLapsDifference = (gcnew System::Windows::Forms::CheckBox());
			this->maskedTextBoxLapsDifference = (gcnew System::Windows::Forms::MaskedTextBox());
			this->checkBoxHideEmptyColumns = (gcnew System::Windows::Forms::CheckBox());
			this->labelStartList = (gcnew System::Windows::Forms::Label());
			this->labelGroupsTimes = (gcnew System::Windows::Forms::Label());
			this->labelResultTimes = (gcnew System::Windows::Forms::Label());
			this->labelRemotePointsDownload = (gcnew System::Windows::Forms::Label());
			this->comboBoxStartListAction = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxGroupsTimesAction = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxResultTimesAction = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxRemotePointsAction = (gcnew System::Windows::Forms::ComboBox());
			this->labelTimeLimit = (gcnew System::Windows::Forms::Label());
			this->textBoxTimeLimit = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxStartCheckList = (gcnew System::Windows::Forms::ComboBox());
			this->checkBoxStartCheckList = (gcnew System::Windows::Forms::CheckBox());
			this->maskedTextBoxStartRegistrationPeriod = (gcnew System::Windows::Forms::MaskedTextBox());
			this->labelRegistrationPeriod = (gcnew System::Windows::Forms::Label());
			this->labelBottom = (gcnew System::Windows::Forms::Label());
			this->textBoxBottom = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxMergeByID = (gcnew System::Windows::Forms::CheckBox());
			this->comboBoxRaceType = (gcnew System::Windows::Forms::ComboBox());
			this->labelRaceType = (gcnew System::Windows::Forms::Label());
			this->labelLapName = (gcnew System::Windows::Forms::Label());
			this->textBoxLapName = (gcnew System::Windows::Forms::TextBox());
			this->labelLapAdditional = (gcnew System::Windows::Forms::Label());
			this->textBoxLapAdditionalInfo = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonStartProtocol
			// 
			this->buttonStartProtocol->Location = System::Drawing::Point(324, 8);
			this->buttonStartProtocol->Name = L"buttonStartProtocol";
			this->buttonStartProtocol->Size = System::Drawing::Size(75, 23);
			this->buttonStartProtocol->TabIndex = 0;
			this->buttonStartProtocol->Text = L"Open";
			this->buttonStartProtocol->UseVisualStyleBackColor = true;
			this->buttonStartProtocol->Click += gcnew System::EventHandler(this, &Form1::buttonStartProtocol_Click);
			// 
			// buttonGroupTime
			// 
			this->buttonGroupTime->Location = System::Drawing::Point(324, 37);
			this->buttonGroupTime->Name = L"buttonGroupTime";
			this->buttonGroupTime->Size = System::Drawing::Size(75, 23);
			this->buttonGroupTime->TabIndex = 1;
			this->buttonGroupTime->Text = L"Open";
			this->buttonGroupTime->UseVisualStyleBackColor = true;
			this->buttonGroupTime->Click += gcnew System::EventHandler(this, &Form1::buttonGroupTime_Click);
			// 
			// buttonFinishTime
			// 
			this->buttonFinishTime->Location = System::Drawing::Point(324, 66);
			this->buttonFinishTime->Name = L"buttonFinishTime";
			this->buttonFinishTime->Size = System::Drawing::Size(75, 23);
			this->buttonFinishTime->TabIndex = 2;
			this->buttonFinishTime->Text = L"Open";
			this->buttonFinishTime->UseVisualStyleBackColor = true;
			this->buttonFinishTime->Click += gcnew System::EventHandler(this, &Form1::buttonFinishTime_Click);
			// 
			// buttonGroupsProtocol
			// 
			this->buttonGroupsProtocol->Location = System::Drawing::Point(324, 95);
			this->buttonGroupsProtocol->Name = L"buttonGroupsProtocol";
			this->buttonGroupsProtocol->Size = System::Drawing::Size(75, 23);
			this->buttonGroupsProtocol->TabIndex = 3;
			this->buttonGroupsProtocol->Text = L"Select";
			this->buttonGroupsProtocol->UseVisualStyleBackColor = true;
			this->buttonGroupsProtocol->Click += gcnew System::EventHandler(this, &Form1::buttonResultsFile_Click);
			// 
			// textBoxStartProtocol
			// 
			this->textBoxStartProtocol->Location = System::Drawing::Point(154, 10);
			this->textBoxStartProtocol->Name = L"textBoxStartProtocol";
			this->textBoxStartProtocol->Size = System::Drawing::Size(164, 20);
			this->textBoxStartProtocol->TabIndex = 5;
			this->textBoxStartProtocol->Text = L"start.txt";
			// 
			// textBoxGroupTime
			// 
			this->textBoxGroupTime->Location = System::Drawing::Point(154, 39);
			this->textBoxGroupTime->Name = L"textBoxGroupTime";
			this->textBoxGroupTime->Size = System::Drawing::Size(164, 20);
			this->textBoxGroupTime->TabIndex = 6;
			this->textBoxGroupTime->Text = L"groups.txt";
			// 
			// textBoxFinishTime
			// 
			this->textBoxFinishTime->Location = System::Drawing::Point(154, 68);
			this->textBoxFinishTime->Name = L"textBoxFinishTime";
			this->textBoxFinishTime->Size = System::Drawing::Size(164, 20);
			this->textBoxFinishTime->TabIndex = 7;
			this->textBoxFinishTime->Text = L"results.txt";
			// 
			// textBoxGroupsProtocol
			// 
			this->textBoxGroupsProtocol->Location = System::Drawing::Point(154, 97);
			this->textBoxGroupsProtocol->Name = L"textBoxGroupsProtocol";
			this->textBoxGroupsProtocol->Size = System::Drawing::Size(164, 20);
			this->textBoxGroupsProtocol->TabIndex = 8;
			this->textBoxGroupsProtocol->Text = L"gr.html";
			// 
			// buttonGenerateProtocol
			// 
			this->buttonGenerateProtocol->Location = System::Drawing::Point(399, 97);
			this->buttonGenerateProtocol->Name = L"buttonGenerateProtocol";
			this->buttonGenerateProtocol->Size = System::Drawing::Size(62, 47);
			this->buttonGenerateProtocol->TabIndex = 15;
			this->buttonGenerateProtocol->Text = L"Generate Protocol";
			this->buttonGenerateProtocol->UseVisualStyleBackColor = true;
			this->buttonGenerateProtocol->Click += gcnew System::EventHandler(this, &Form1::buttonGenerateProtocol_Click);
			// 
			// textBoAbsoluteProtocol
			// 
			this->textBoAbsoluteProtocol->Location = System::Drawing::Point(154, 124);
			this->textBoAbsoluteProtocol->Name = L"textBoAbsoluteProtocol";
			this->textBoAbsoluteProtocol->Size = System::Drawing::Size(164, 20);
			this->textBoAbsoluteProtocol->TabIndex = 17;
			this->textBoAbsoluteProtocol->Text = L"abs.html";
			// 
			// buttonAbsoluteProtocol
			// 
			this->buttonAbsoluteProtocol->Location = System::Drawing::Point(324, 122);
			this->buttonAbsoluteProtocol->Name = L"buttonAbsoluteProtocol";
			this->buttonAbsoluteProtocol->Size = System::Drawing::Size(75, 23);
			this->buttonAbsoluteProtocol->TabIndex = 18;
			this->buttonAbsoluteProtocol->Text = L"Select";
			this->buttonAbsoluteProtocol->UseVisualStyleBackColor = true;
			this->buttonAbsoluteProtocol->Click += gcnew System::EventHandler(this, &Form1::buttonAbsoluteProtocol_Click);
			// 
			// checkBoxDisableDNF
			// 
			this->checkBoxDisableDNF->AutoSize = true;
			this->checkBoxDisableDNF->Location = System::Drawing::Point(538, 365);
			this->checkBoxDisableDNF->Name = L"checkBoxDisableDNF";
			this->checkBoxDisableDNF->Size = System::Drawing::Size(86, 17);
			this->checkBoxDisableDNF->TabIndex = 19;
			this->checkBoxDisableDNF->Text = L"Disable DNF";
			this->checkBoxDisableDNF->UseVisualStyleBackColor = true;
			// 
			// checkBoxDisableDSQ
			// 
			this->checkBoxDisableDSQ->AutoSize = true;
			this->checkBoxDisableDSQ->Location = System::Drawing::Point(445, 363);
			this->checkBoxDisableDSQ->Name = L"checkBoxDisableDSQ";
			this->checkBoxDisableDSQ->Size = System::Drawing::Size(87, 17);
			this->checkBoxDisableDSQ->TabIndex = 20;
			this->checkBoxDisableDSQ->Text = L"Disable DSQ";
			this->checkBoxDisableDSQ->UseVisualStyleBackColor = true;
			// 
			// checkBoxUseFileLogger
			// 
			this->checkBoxUseFileLogger->AutoSize = true;
			this->checkBoxUseFileLogger->Location = System::Drawing::Point(6, 179);
			this->checkBoxUseFileLogger->Name = L"checkBoxUseFileLogger";
			this->checkBoxUseFileLogger->Size = System::Drawing::Size(100, 17);
			this->checkBoxUseFileLogger->TabIndex = 21;
			this->checkBoxUseFileLogger->Text = L"Use File Logger";
			this->checkBoxUseFileLogger->UseVisualStyleBackColor = true;
			// 
			// listBoxLogger
			// 
			this->listBoxLogger->FormattingEnabled = true;
			this->listBoxLogger->HorizontalScrollbar = true;
			this->listBoxLogger->Location = System::Drawing::Point(11, 278);
			this->listBoxLogger->Name = L"listBoxLogger";
			this->listBoxLogger->Size = System::Drawing::Size(386, 264);
			this->listBoxLogger->TabIndex = 22;
			// 
			// labelLoggerInfo
			// 
			this->labelLoggerInfo->AutoSize = true;
			this->labelLoggerInfo->ForeColor = System::Drawing::Color::Black;
			this->labelLoggerInfo->Location = System::Drawing::Point(12, 545);
			this->labelLoggerInfo->Name = L"labelLoggerInfo";
			this->labelLoggerInfo->Size = System::Drawing::Size(118, 13);
			this->labelLoggerInfo->TabIndex = 23;
			this->labelLoggerInfo->Text = L"Errors - 0; Warnings - 0.";
			// 
			// textBoxLogSearch
			// 
			this->textBoxLogSearch->Location = System::Drawing::Point(76, 254);
			this->textBoxLogSearch->Name = L"textBoxLogSearch";
			this->textBoxLogSearch->Size = System::Drawing::Size(238, 20);
			this->textBoxLogSearch->TabIndex = 24;
			this->textBoxLogSearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBoxLogSearch_KeyDown);
			// 
			// buttonLogSearch
			// 
			this->buttonLogSearch->Location = System::Drawing::Point(324, 252);
			this->buttonLogSearch->Name = L"buttonLogSearch";
			this->buttonLogSearch->Size = System::Drawing::Size(75, 23);
			this->buttonLogSearch->TabIndex = 25;
			this->buttonLogSearch->Text = L"Find";
			this->buttonLogSearch->UseVisualStyleBackColor = true;
			this->buttonLogSearch->Click += gcnew System::EventHandler(this, &Form1::buttonLogSearch_Click);
			// 
			// labelLogSearch
			// 
			this->labelLogSearch->AutoSize = true;
			this->labelLogSearch->Location = System::Drawing::Point(8, 257);
			this->labelLogSearch->Name = L"labelLogSearch";
			this->labelLogSearch->Size = System::Drawing::Size(62, 13);
			this->labelLogSearch->TabIndex = 26;
			this->labelLogSearch->Text = L"Log Search";
			// 
			// labelRaceName
			// 
			this->labelRaceName->AutoSize = true;
			this->labelRaceName->Location = System::Drawing::Point(462, 42);
			this->labelRaceName->Name = L"labelRaceName";
			this->labelRaceName->Size = System::Drawing::Size(64, 13);
			this->labelRaceName->TabIndex = 28;
			this->labelRaceName->Text = L"Race Name";
			// 
			// labelRaceDate
			// 
			this->labelRaceDate->AutoSize = true;
			this->labelRaceDate->Location = System::Drawing::Point(462, 71);
			this->labelRaceDate->Name = L"labelRaceDate";
			this->labelRaceDate->Size = System::Drawing::Size(59, 13);
			this->labelRaceDate->TabIndex = 29;
			this->labelRaceDate->Text = L"Race Date";
			// 
			// labelRacePlace
			// 
			this->labelRacePlace->AutoSize = true;
			this->labelRacePlace->Location = System::Drawing::Point(462, 100);
			this->labelRacePlace->Name = L"labelRacePlace";
			this->labelRacePlace->Size = System::Drawing::Size(63, 13);
			this->labelRacePlace->TabIndex = 30;
			this->labelRacePlace->Text = L"Race Place";
			// 
			// labelWeather
			// 
			this->labelWeather->AutoSize = true;
			this->labelWeather->Location = System::Drawing::Point(462, 127);
			this->labelWeather->Name = L"labelWeather";
			this->labelWeather->Size = System::Drawing::Size(48, 13);
			this->labelWeather->TabIndex = 31;
			this->labelWeather->Text = L"Weather";
			// 
			// textBoxRaceName
			// 
			this->textBoxRaceName->Location = System::Drawing::Point(565, 39);
			this->textBoxRaceName->Name = L"textBoxRaceName";
			this->textBoxRaceName->Size = System::Drawing::Size(228, 20);
			this->textBoxRaceName->TabIndex = 32;
			// 
			// textBoxRaceDate
			// 
			this->textBoxRaceDate->Location = System::Drawing::Point(565, 68);
			this->textBoxRaceDate->Name = L"textBoxRaceDate";
			this->textBoxRaceDate->Size = System::Drawing::Size(228, 20);
			this->textBoxRaceDate->TabIndex = 33;
			// 
			// textBoxRacePlace
			// 
			this->textBoxRacePlace->Location = System::Drawing::Point(565, 97);
			this->textBoxRacePlace->Name = L"textBoxRacePlace";
			this->textBoxRacePlace->Size = System::Drawing::Size(228, 20);
			this->textBoxRacePlace->TabIndex = 34;
			// 
			// textBoxWeather
			// 
			this->textBoxWeather->Location = System::Drawing::Point(565, 124);
			this->textBoxWeather->Name = L"textBoxWeather";
			this->textBoxWeather->Size = System::Drawing::Size(228, 20);
			this->textBoxWeather->TabIndex = 35;
			// 
			// textBoxMainReferee
			// 
			this->textBoxMainReferee->Location = System::Drawing::Point(565, 150);
			this->textBoxMainReferee->Name = L"textBoxMainReferee";
			this->textBoxMainReferee->Size = System::Drawing::Size(228, 20);
			this->textBoxMainReferee->TabIndex = 36;
			// 
			// textBoxAdditionalReferee
			// 
			this->textBoxAdditionalReferee->Location = System::Drawing::Point(565, 176);
			this->textBoxAdditionalReferee->Name = L"textBoxAdditionalReferee";
			this->textBoxAdditionalReferee->Size = System::Drawing::Size(228, 20);
			this->textBoxAdditionalReferee->TabIndex = 37;
			// 
			// labelMainReferee
			// 
			this->labelMainReferee->AutoSize = true;
			this->labelMainReferee->Location = System::Drawing::Point(462, 153);
			this->labelMainReferee->Name = L"labelMainReferee";
			this->labelMainReferee->Size = System::Drawing::Size(76, 13);
			this->labelMainReferee->TabIndex = 38;
			this->labelMainReferee->Text = L"Referee Name";
			// 
			// labelAdditionalReferee
			// 
			this->labelAdditionalReferee->AutoSize = true;
			this->labelAdditionalReferee->Location = System::Drawing::Point(462, 179);
			this->labelAdditionalReferee->Name = L"labelAdditionalReferee";
			this->labelAdditionalReferee->Size = System::Drawing::Size(83, 13);
			this->labelAdditionalReferee->TabIndex = 39;
			this->labelAdditionalReferee->Text = L"Secretary Name";
			// 
			// labelOrganizator
			// 
			this->labelOrganizator->AutoSize = true;
			this->labelOrganizator->Location = System::Drawing::Point(462, 206);
			this->labelOrganizator->Name = L"labelOrganizator";
			this->labelOrganizator->Size = System::Drawing::Size(67, 13);
			this->labelOrganizator->TabIndex = 40;
			this->labelOrganizator->Text = L"Organinzator";
			// 
			// textBoxOrganizator
			// 
			this->textBoxOrganizator->Location = System::Drawing::Point(565, 203);
			this->textBoxOrganizator->Name = L"textBoxOrganizator";
			this->textBoxOrganizator->Size = System::Drawing::Size(228, 20);
			this->textBoxOrganizator->TabIndex = 41;
			// 
			// labelTrackConditions
			// 
			this->labelTrackConditions->AutoSize = true;
			this->labelTrackConditions->Location = System::Drawing::Point(462, 234);
			this->labelTrackConditions->Name = L"labelTrackConditions";
			this->labelTrackConditions->Size = System::Drawing::Size(86, 13);
			this->labelTrackConditions->TabIndex = 42;
			this->labelTrackConditions->Text = L"Track conditions";
			// 
			// textBoxTrackConditions
			// 
			this->textBoxTrackConditions->Location = System::Drawing::Point(565, 231);
			this->textBoxTrackConditions->Name = L"textBoxTrackConditions";
			this->textBoxTrackConditions->Size = System::Drawing::Size(90, 20);
			this->textBoxTrackConditions->TabIndex = 43;
			// 
			// labelMinimalTimeForLap
			// 
			this->labelMinimalTimeForLap->AutoSize = true;
			this->labelMinimalTimeForLap->Location = System::Drawing::Point(462, 260);
			this->labelMinimalTimeForLap->Name = L"labelMinimalTimeForLap";
			this->labelMinimalTimeForLap->Size = System::Drawing::Size(167, 13);
			this->labelMinimalTimeForLap->TabIndex = 44;
			this->labelMinimalTimeForLap->Text = L"Minimal Time For Lap (in seconds)";
			// 
			// textBoxMinimalTimeForLap
			// 
			this->textBoxMinimalTimeForLap->Location = System::Drawing::Point(644, 257);
			this->textBoxMinimalTimeForLap->Name = L"textBoxMinimalTimeForLap";
			this->textBoxMinimalTimeForLap->Size = System::Drawing::Size(51, 20);
			this->textBoxMinimalTimeForLap->TabIndex = 46;
			// 
			// checkBoxUseInterfaceLogger
			// 
			this->checkBoxUseInterfaceLogger->AutoSize = true;
			this->checkBoxUseInterfaceLogger->Location = System::Drawing::Point(104, 178);
			this->checkBoxUseInterfaceLogger->Name = L"checkBoxUseInterfaceLogger";
			this->checkBoxUseInterfaceLogger->Size = System::Drawing::Size(126, 17);
			this->checkBoxUseInterfaceLogger->TabIndex = 47;
			this->checkBoxUseInterfaceLogger->Text = L"Use Interface Logger";
			this->checkBoxUseInterfaceLogger->UseVisualStyleBackColor = true;
			// 
			// buttonLoadRaceInfoData
			// 
			this->buttonLoadRaceInfoData->Location = System::Drawing::Point(630, 312);
			this->buttonLoadRaceInfoData->Name = L"buttonLoadRaceInfoData";
			this->buttonLoadRaceInfoData->Size = System::Drawing::Size(105, 23);
			this->buttonLoadRaceInfoData->TabIndex = 48;
			this->buttonLoadRaceInfoData->Text = L"Load Race Info Data";
			this->buttonLoadRaceInfoData->UseVisualStyleBackColor = true;
			this->buttonLoadRaceInfoData->Click += gcnew System::EventHandler(this, &Form1::buttonLoadRaceInfoData_Click);
			// 
			// textBoxNumberOfSignsAfterPoint
			// 
			this->textBoxNumberOfSignsAfterPoint->Location = System::Drawing::Point(644, 283);
			this->textBoxNumberOfSignsAfterPoint->Name = L"textBoxNumberOfSignsAfterPoint";
			this->textBoxNumberOfSignsAfterPoint->Size = System::Drawing::Size(51, 20);
			this->textBoxNumberOfSignsAfterPoint->TabIndex = 50;
			// 
			// labelNumberOfSignsAfterPoint
			// 
			this->labelNumberOfSignsAfterPoint->AutoSize = true;
			this->labelNumberOfSignsAfterPoint->Location = System::Drawing::Point(462, 286);
			this->labelNumberOfSignsAfterPoint->Name = L"labelNumberOfSignsAfterPoint";
			this->labelNumberOfSignsAfterPoint->Size = System::Drawing::Size(176, 13);
			this->labelNumberOfSignsAfterPoint->TabIndex = 51;
			this->labelNumberOfSignsAfterPoint->Text = L"Number of  Signs after Point in Time";
			// 
			// checkBoxShowID
			// 
			this->checkBoxShowID->AutoSize = true;
			this->checkBoxShowID->Checked = true;
			this->checkBoxShowID->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowID->Location = System::Drawing::Point(465, 417);
			this->checkBoxShowID->Name = L"checkBoxShowID";
			this->checkBoxShowID->Size = System::Drawing::Size(37, 17);
			this->checkBoxShowID->TabIndex = 52;
			this->checkBoxShowID->Text = L"ID";
			this->checkBoxShowID->UseVisualStyleBackColor = true;
			this->checkBoxShowID->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowID_CheckedChanged);
			// 
			// checkBoxShowName
			// 
			this->checkBoxShowName->AutoSize = true;
			this->checkBoxShowName->Checked = true;
			this->checkBoxShowName->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowName->Location = System::Drawing::Point(630, 417);
			this->checkBoxShowName->Name = L"checkBoxShowName";
			this->checkBoxShowName->Size = System::Drawing::Size(54, 17);
			this->checkBoxShowName->TabIndex = 53;
			this->checkBoxShowName->Text = L"Name";
			this->checkBoxShowName->UseVisualStyleBackColor = true;
			this->checkBoxShowName->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowName_CheckedChanged);
			// 
			// checkBoxShowAge
			// 
			this->checkBoxShowAge->AutoSize = true;
			this->checkBoxShowAge->Checked = true;
			this->checkBoxShowAge->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowAge->Location = System::Drawing::Point(465, 440);
			this->checkBoxShowAge->Name = L"checkBoxShowAge";
			this->checkBoxShowAge->Size = System::Drawing::Size(45, 17);
			this->checkBoxShowAge->TabIndex = 54;
			this->checkBoxShowAge->Text = L"Age";
			this->checkBoxShowAge->UseVisualStyleBackColor = true;
			this->checkBoxShowAge->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowAge_CheckedChanged);
			// 
			// checkBoxShowTeam
			// 
			this->checkBoxShowTeam->AutoSize = true;
			this->checkBoxShowTeam->Checked = true;
			this->checkBoxShowTeam->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowTeam->Location = System::Drawing::Point(630, 440);
			this->checkBoxShowTeam->Name = L"checkBoxShowTeam";
			this->checkBoxShowTeam->Size = System::Drawing::Size(53, 17);
			this->checkBoxShowTeam->TabIndex = 55;
			this->checkBoxShowTeam->Text = L"Team";
			this->checkBoxShowTeam->UseVisualStyleBackColor = true;
			this->checkBoxShowTeam->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowTeam_CheckedChanged);
			// 
			// checkBoxShowCity
			// 
			this->checkBoxShowCity->AutoSize = true;
			this->checkBoxShowCity->Checked = true;
			this->checkBoxShowCity->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowCity->Location = System::Drawing::Point(465, 463);
			this->checkBoxShowCity->Name = L"checkBoxShowCity";
			this->checkBoxShowCity->Size = System::Drawing::Size(43, 17);
			this->checkBoxShowCity->TabIndex = 56;
			this->checkBoxShowCity->Text = L"City";
			this->checkBoxShowCity->UseVisualStyleBackColor = true;
			this->checkBoxShowCity->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowCity_CheckedChanged);
			// 
			// checkBoxShowLapTimes
			// 
			this->checkBoxShowLapTimes->AutoSize = true;
			this->checkBoxShowLapTimes->Checked = true;
			this->checkBoxShowLapTimes->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowLapTimes->Location = System::Drawing::Point(630, 463);
			this->checkBoxShowLapTimes->Name = L"checkBoxShowLapTimes";
			this->checkBoxShowLapTimes->Size = System::Drawing::Size(49, 17);
			this->checkBoxShowLapTimes->TabIndex = 57;
			this->checkBoxShowLapTimes->Text = L"Laps";
			this->checkBoxShowLapTimes->UseVisualStyleBackColor = true;
			this->checkBoxShowLapTimes->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowLapTimes_CheckedChanged);
			// 
			// checkBoxShowFinishTime
			// 
			this->checkBoxShowFinishTime->AutoSize = true;
			this->checkBoxShowFinishTime->Checked = true;
			this->checkBoxShowFinishTime->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowFinishTime->Location = System::Drawing::Point(465, 486);
			this->checkBoxShowFinishTime->Name = L"checkBoxShowFinishTime";
			this->checkBoxShowFinishTime->Size = System::Drawing::Size(53, 17);
			this->checkBoxShowFinishTime->TabIndex = 58;
			this->checkBoxShowFinishTime->Text = L"Finish";
			this->checkBoxShowFinishTime->UseVisualStyleBackColor = true;
			this->checkBoxShowFinishTime->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowFinishTime_CheckedChanged);
			// 
			// checkBoxShowGroup
			// 
			this->checkBoxShowGroup->AutoSize = true;
			this->checkBoxShowGroup->Checked = true;
			this->checkBoxShowGroup->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowGroup->Location = System::Drawing::Point(630, 486);
			this->checkBoxShowGroup->Name = L"checkBoxShowGroup";
			this->checkBoxShowGroup->Size = System::Drawing::Size(55, 17);
			this->checkBoxShowGroup->TabIndex = 59;
			this->checkBoxShowGroup->Text = L"Group";
			this->checkBoxShowGroup->UseVisualStyleBackColor = true;
			this->checkBoxShowGroup->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowGroup_CheckedChanged);
			// 
			// checkBoxShowPlace
			// 
			this->checkBoxShowPlace->AutoSize = true;
			this->checkBoxShowPlace->Checked = true;
			this->checkBoxShowPlace->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowPlace->Location = System::Drawing::Point(465, 509);
			this->checkBoxShowPlace->Name = L"checkBoxShowPlace";
			this->checkBoxShowPlace->Size = System::Drawing::Size(53, 17);
			this->checkBoxShowPlace->TabIndex = 60;
			this->checkBoxShowPlace->Text = L"Place";
			this->checkBoxShowPlace->UseVisualStyleBackColor = true;
			this->checkBoxShowPlace->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowPlace_CheckedChanged);
			// 
			// checkBoxStratch
			// 
			this->checkBoxStratch->AutoSize = true;
			this->checkBoxStratch->Checked = true;
			this->checkBoxStratch->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxStratch->Location = System::Drawing::Point(701, 530);
			this->checkBoxStratch->Name = L"checkBoxStratch";
			this->checkBoxStratch->Size = System::Drawing::Size(60, 17);
			this->checkBoxStratch->TabIndex = 61;
			this->checkBoxStratch->Text = L"Stratch";
			this->checkBoxStratch->UseVisualStyleBackColor = true;
			// 
			// checkBoxPrintDNF
			// 
			this->checkBoxPrintDNF->AutoSize = true;
			this->checkBoxPrintDNF->Checked = true;
			this->checkBoxPrintDNF->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxPrintDNF->Location = System::Drawing::Point(465, 533);
			this->checkBoxPrintDNF->Name = L"checkBoxPrintDNF";
			this->checkBoxPrintDNF->Size = System::Drawing::Size(72, 17);
			this->checkBoxPrintDNF->TabIndex = 62;
			this->checkBoxPrintDNF->Text = L"Print DNF";
			this->checkBoxPrintDNF->UseVisualStyleBackColor = true;
			this->checkBoxPrintDNF->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxPrintDNF_CheckedChanged);
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(524, 415);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(100, 20);
			this->textBoxID->TabIndex = 63;
			this->textBoxID->Text = L"Стартовый Номер";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(696, 415);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(100, 20);
			this->textBoxName->TabIndex = 64;
			this->textBoxName->Text = L"Фамилия Имя";
			// 
			// textBoxAge
			// 
			this->textBoxAge->Location = System::Drawing::Point(524, 438);
			this->textBoxAge->Name = L"textBoxAge";
			this->textBoxAge->Size = System::Drawing::Size(100, 20);
			this->textBoxAge->TabIndex = 65;
			this->textBoxAge->Text = L"Год рождения";
			// 
			// textBoxCity
			// 
			this->textBoxCity->Location = System::Drawing::Point(524, 461);
			this->textBoxCity->Name = L"textBoxCity";
			this->textBoxCity->Size = System::Drawing::Size(100, 20);
			this->textBoxCity->TabIndex = 66;
			this->textBoxCity->Text = L"Город";
			// 
			// textBoxPlace
			// 
			this->textBoxPlace->Location = System::Drawing::Point(524, 507);
			this->textBoxPlace->Name = L"textBoxPlace";
			this->textBoxPlace->Size = System::Drawing::Size(100, 20);
			this->textBoxPlace->TabIndex = 68;
			this->textBoxPlace->Text = L"Место";
			// 
			// textBoxTeam
			// 
			this->textBoxTeam->Location = System::Drawing::Point(696, 438);
			this->textBoxTeam->Name = L"textBoxTeam";
			this->textBoxTeam->Size = System::Drawing::Size(100, 20);
			this->textBoxTeam->TabIndex = 69;
			this->textBoxTeam->Text = L"Команда";
			// 
			// textBoxGroup
			// 
			this->textBoxGroup->Location = System::Drawing::Point(696, 484);
			this->textBoxGroup->Name = L"textBoxGroup";
			this->textBoxGroup->Size = System::Drawing::Size(100, 20);
			this->textBoxGroup->TabIndex = 71;
			this->textBoxGroup->Text = L"Группа";
			// 
			// checkBoxLapFinnish
			// 
			this->checkBoxLapFinnish->AutoSize = true;
			this->checkBoxLapFinnish->Checked = true;
			this->checkBoxLapFinnish->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxLapFinnish->Location = System::Drawing::Point(675, 463);
			this->checkBoxLapFinnish->Name = L"checkBoxLapFinnish";
			this->checkBoxLapFinnish->Size = System::Drawing::Size(74, 17);
			this->checkBoxLapFinnish->TabIndex = 73;
			this->checkBoxLapFinnish->Text = L"Lap Finish";
			this->checkBoxLapFinnish->UseVisualStyleBackColor = true;
			// 
			// checkBoxTimeDifference
			// 
			this->checkBoxTimeDifference->AutoSize = true;
			this->checkBoxTimeDifference->Checked = true;
			this->checkBoxTimeDifference->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxTimeDifference->Location = System::Drawing::Point(513, 486);
			this->checkBoxTimeDifference->Name = L"checkBoxTimeDifference";
			this->checkBoxTimeDifference->Size = System::Drawing::Size(68, 17);
			this->checkBoxTimeDifference->TabIndex = 74;
			this->checkBoxTimeDifference->Text = L"Time Diff";
			this->checkBoxTimeDifference->UseVisualStyleBackColor = true;
			// 
			// textBoxReferee
			// 
			this->textBoxReferee->Location = System::Drawing::Point(696, 363);
			this->textBoxReferee->Name = L"textBoxReferee";
			this->textBoxReferee->Size = System::Drawing::Size(100, 20);
			this->textBoxReferee->TabIndex = 75;
			this->textBoxReferee->Text = L"Главный судья";
			// 
			// textBoxSecretary
			// 
			this->textBoxSecretary->Location = System::Drawing::Point(696, 389);
			this->textBoxSecretary->Name = L"textBoxSecretary";
			this->textBoxSecretary->Size = System::Drawing::Size(100, 20);
			this->textBoxSecretary->TabIndex = 76;
			this->textBoxSecretary->Text = L"Главный секретарь";
			// 
			// labelRefereeText
			// 
			this->labelRefereeText->AutoSize = true;
			this->labelRefereeText->Location = System::Drawing::Point(627, 366);
			this->labelRefereeText->Name = L"labelRefereeText";
			this->labelRefereeText->Size = System::Drawing::Size(45, 13);
			this->labelRefereeText->TabIndex = 77;
			this->labelRefereeText->Text = L"Referee";
			// 
			// labelSecretary
			// 
			this->labelSecretary->AutoSize = true;
			this->labelSecretary->Location = System::Drawing::Point(627, 392);
			this->labelSecretary->Name = L"labelSecretary";
			this->labelSecretary->Size = System::Drawing::Size(52, 13);
			this->labelSecretary->TabIndex = 78;
			this->labelSecretary->Text = L"Secretary";
			// 
			// checkBoxPrintDNS
			// 
			this->checkBoxPrintDNS->AutoSize = true;
			this->checkBoxPrintDNS->Location = System::Drawing::Point(543, 533);
			this->checkBoxPrintDNS->Name = L"checkBoxPrintDNS";
			this->checkBoxPrintDNS->Size = System::Drawing::Size(73, 17);
			this->checkBoxPrintDNS->TabIndex = 79;
			this->checkBoxPrintDNS->Text = L"Print DNS";
			this->checkBoxPrintDNS->UseVisualStyleBackColor = true;
			// 
			// checkBoxPrintDSQ
			// 
			this->checkBoxPrintDSQ->AutoSize = true;
			this->checkBoxPrintDSQ->Checked = true;
			this->checkBoxPrintDSQ->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxPrintDSQ->Location = System::Drawing::Point(622, 533);
			this->checkBoxPrintDSQ->Name = L"checkBoxPrintDSQ";
			this->checkBoxPrintDSQ->Size = System::Drawing::Size(73, 17);
			this->checkBoxPrintDSQ->TabIndex = 80;
			this->checkBoxPrintDSQ->Text = L"Print DSQ";
			this->checkBoxPrintDSQ->UseVisualStyleBackColor = true;
			// 
			// checkBoxErrAndWrnOnly
			// 
			this->checkBoxErrAndWrnOnly->AutoSize = true;
			this->checkBoxErrAndWrnOnly->Location = System::Drawing::Point(224, 178);
			this->checkBoxErrAndWrnOnly->Name = L"checkBoxErrAndWrnOnly";
			this->checkBoxErrAndWrnOnly->Size = System::Drawing::Size(105, 17);
			this->checkBoxErrAndWrnOnly->TabIndex = 81;
			this->checkBoxErrAndWrnOnly->Text = L"Err and Wrn only";
			this->checkBoxErrAndWrnOnly->UseVisualStyleBackColor = true;
			// 
			// checkBoxAdditionalInfo
			// 
			this->checkBoxAdditionalInfo->AutoSize = true;
			this->checkBoxAdditionalInfo->Location = System::Drawing::Point(630, 341);
			this->checkBoxAdditionalInfo->Name = L"checkBoxAdditionalInfo";
			this->checkBoxAdditionalInfo->Size = System::Drawing::Size(44, 17);
			this->checkBoxAdditionalInfo->TabIndex = 82;
			this->checkBoxAdditionalInfo->Text = L"Info";
			this->checkBoxAdditionalInfo->UseVisualStyleBackColor = true;
			// 
			// textBoxAdditonalInfo
			// 
			this->textBoxAdditonalInfo->Location = System::Drawing::Point(696, 337);
			this->textBoxAdditonalInfo->Name = L"textBoxAdditonalInfo";
			this->textBoxAdditonalInfo->Size = System::Drawing::Size(100, 20);
			this->textBoxAdditonalInfo->TabIndex = 83;
			this->textBoxAdditonalInfo->Text = L"Дополнительная информация об участнике";
			// 
			// buttonRefreshTimeSubmit
			// 
			this->buttonRefreshTimeSubmit->Location = System::Drawing::Point(596, 11);
			this->buttonRefreshTimeSubmit->Name = L"buttonRefreshTimeSubmit";
			this->buttonRefreshTimeSubmit->Size = System::Drawing::Size(59, 23);
			this->buttonRefreshTimeSubmit->TabIndex = 84;
			this->buttonRefreshTimeSubmit->Text = L"Submit";
			this->buttonRefreshTimeSubmit->UseVisualStyleBackColor = true;
			this->buttonRefreshTimeSubmit->Click += gcnew System::EventHandler(this, &Form1::buttonRefreshTimeSubmit_Click);
			// 
			// maskedTextBoxRefreshTime
			// 
			this->maskedTextBoxRefreshTime->Enabled = false;
			this->maskedTextBoxRefreshTime->Location = System::Drawing::Point(534, 13);
			this->maskedTextBoxRefreshTime->Name = L"maskedTextBoxRefreshTime";
			this->maskedTextBoxRefreshTime->Size = System::Drawing::Size(56, 20);
			this->maskedTextBoxRefreshTime->TabIndex = 86;
			this->maskedTextBoxRefreshTime->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBoxRefreshTime_MaskInputRejected);
			// 
			// checkBoxRefresh
			// 
			this->checkBoxRefresh->AutoSize = true;
			this->checkBoxRefresh->Location = System::Drawing::Point(465, 15);
			this->checkBoxRefresh->Name = L"checkBoxRefresh";
			this->checkBoxRefresh->Size = System::Drawing::Size(63, 17);
			this->checkBoxRefresh->TabIndex = 87;
			this->checkBoxRefresh->Text = L"Refresh";
			this->checkBoxRefresh->UseVisualStyleBackColor = true;
			this->checkBoxRefresh->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxRefresh_CheckedChanged);
			// 
			// timerRefresh
			// 
			this->timerRefresh->Interval = 10;
			this->timerRefresh->Tick += gcnew System::EventHandler(this, &Form1::timerRefresh_Tick);
			// 
			// buttonSaveRaceInfo
			// 
			this->buttonSaveRaceInfo->Location = System::Drawing::Point(741, 312);
			this->buttonSaveRaceInfo->Name = L"buttonSaveRaceInfo";
			this->buttonSaveRaceInfo->Size = System::Drawing::Size(56, 23);
			this->buttonSaveRaceInfo->TabIndex = 88;
			this->buttonSaveRaceInfo->Text = L"Save";
			this->buttonSaveRaceInfo->UseVisualStyleBackColor = true;
			this->buttonSaveRaceInfo->Click += gcnew System::EventHandler(this, &Form1::buttonSaveRaceInfo_Click);
			// 
			// checkBoxTimeShift
			// 
			this->checkBoxTimeShift->AutoSize = true;
			this->checkBoxTimeShift->Location = System::Drawing::Point(628, 509);
			this->checkBoxTimeShift->Name = L"checkBoxTimeShift";
			this->checkBoxTimeShift->Size = System::Drawing::Size(73, 17);
			this->checkBoxTimeShift->TabIndex = 89;
			this->checkBoxTimeShift->Text = L"Time Shift";
			this->checkBoxTimeShift->UseVisualStyleBackColor = true;
			// 
			// textBoxTimeShift
			// 
			this->textBoxTimeShift->Location = System::Drawing::Point(696, 507);
			this->textBoxTimeShift->Name = L"textBoxTimeShift";
			this->textBoxTimeShift->Size = System::Drawing::Size(100, 20);
			this->textBoxTimeShift->TabIndex = 90;
			this->textBoxTimeShift->Text = L"Задержка старта";
			// 
			// checkBoxButtons
			// 
			this->checkBoxButtons->AutoSize = true;
			this->checkBoxButtons->Location = System::Drawing::Point(465, 391);
			this->checkBoxButtons->Name = L"checkBoxButtons";
			this->checkBoxButtons->Size = System::Drawing::Size(95, 17);
			this->checkBoxButtons->TabIndex = 91;
			this->checkBoxButtons->Text = L"Remote Points";
			this->checkBoxButtons->UseVisualStyleBackColor = true;
			// 
			// textBoxRemotePointsNumber
			// 
			this->textBoxRemotePointsNumber->Location = System::Drawing::Point(11, 227);
			this->textBoxRemotePointsNumber->Name = L"textBoxRemotePointsNumber";
			this->textBoxRemotePointsNumber->Size = System::Drawing::Size(27, 20);
			this->textBoxRemotePointsNumber->TabIndex = 92;
			this->textBoxRemotePointsNumber->Text = L"0";
			// 
			// textBoxRemotePoints
			// 
			this->textBoxRemotePoints->Location = System::Drawing::Point(126, 227);
			this->textBoxRemotePoints->Name = L"textBoxRemotePoints";
			this->textBoxRemotePoints->Size = System::Drawing::Size(183, 20);
			this->textBoxRemotePoints->TabIndex = 93;
			// 
			// labelRemotePoints
			// 
			this->labelRemotePoints->AutoSize = true;
			this->labelRemotePoints->Location = System::Drawing::Point(44, 230);
			this->labelRemotePoints->Name = L"labelRemotePoints";
			this->labelRemotePoints->Size = System::Drawing::Size(76, 13);
			this->labelRemotePoints->TabIndex = 94;
			this->labelRemotePoints->Text = L"Remote Points";
			// 
			// buttonRemotePoints
			// 
			this->buttonRemotePoints->Location = System::Drawing::Point(315, 224);
			this->buttonRemotePoints->Name = L"buttonRemotePoints";
			this->buttonRemotePoints->Size = System::Drawing::Size(84, 23);
			this->buttonRemotePoints->TabIndex = 95;
			this->buttonRemotePoints->Text = L"Select Folder";
			this->buttonRemotePoints->UseVisualStyleBackColor = true;
			this->buttonRemotePoints->Click += gcnew System::EventHandler(this, &Form1::buttonRemotePoints_Click);
			// 
			// checkBoxAllButtons
			// 
			this->checkBoxAllButtons->AutoSize = true;
			this->checkBoxAllButtons->Location = System::Drawing::Point(555, 391);
			this->checkBoxAllButtons->Name = L"checkBoxAllButtons";
			this->checkBoxAllButtons->Size = System::Drawing::Size(83, 17);
			this->checkBoxAllButtons->TabIndex = 96;
			this->checkBoxAllButtons->Text = L"Info Buttons";
			this->checkBoxAllButtons->UseVisualStyleBackColor = true;
			// 
			// checkBoxUploadGroups
			// 
			this->checkBoxUploadGroups->AutoSize = true;
			this->checkBoxUploadGroups->Location = System::Drawing::Point(11, 99);
			this->checkBoxUploadGroups->Name = L"checkBoxUploadGroups";
			this->checkBoxUploadGroups->Size = System::Drawing::Size(139, 17);
			this->checkBoxUploadGroups->TabIndex = 97;
			this->checkBoxUploadGroups->Text = L"Upload Groups Protocol";
			this->checkBoxUploadGroups->UseVisualStyleBackColor = true;
			this->checkBoxUploadGroups->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxUploadDownload_CheckedChanged);
			// 
			// textBoxFTPPath
			// 
			this->textBoxFTPPath->Enabled = false;
			this->textBoxFTPPath->Location = System::Drawing::Point(171, 201);
			this->textBoxFTPPath->Name = L"textBoxFTPPath";
			this->textBoxFTPPath->Size = System::Drawing::Size(73, 20);
			this->textBoxFTPPath->TabIndex = 98;
			this->textBoxFTPPath->Text = L"FTP Path";
			// 
			// textBoxFTPLogin
			// 
			this->textBoxFTPLogin->Enabled = false;
			this->textBoxFTPLogin->Location = System::Drawing::Point(250, 201);
			this->textBoxFTPLogin->Name = L"textBoxFTPLogin";
			this->textBoxFTPLogin->Size = System::Drawing::Size(68, 20);
			this->textBoxFTPLogin->TabIndex = 99;
			this->textBoxFTPLogin->Text = L"Login";
			this->textBoxFTPLogin->Visible = false;
			// 
			// textBoxFTPPassword
			// 
			this->textBoxFTPPassword->Enabled = false;
			this->textBoxFTPPassword->Location = System::Drawing::Point(324, 201);
			this->textBoxFTPPassword->Name = L"textBoxFTPPassword";
			this->textBoxFTPPassword->Size = System::Drawing::Size(75, 20);
			this->textBoxFTPPassword->TabIndex = 100;
			this->textBoxFTPPassword->Text = L"Password";
			this->textBoxFTPPassword->Visible = false;
			// 
			// checkBoxUploadAbsolute
			// 
			this->checkBoxUploadAbsolute->AutoSize = true;
			this->checkBoxUploadAbsolute->Location = System::Drawing::Point(11, 126);
			this->checkBoxUploadAbsolute->Name = L"checkBoxUploadAbsolute";
			this->checkBoxUploadAbsolute->Size = System::Drawing::Size(142, 17);
			this->checkBoxUploadAbsolute->TabIndex = 102;
			this->checkBoxUploadAbsolute->Text = L"Upload Absolout Pritocol";
			this->checkBoxUploadAbsolute->UseVisualStyleBackColor = true;
			this->checkBoxUploadAbsolute->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxUploadAbsolute_CheckedChanged);
			// 
			// checkBoxShowLoginPassword
			// 
			this->checkBoxShowLoginPassword->AutoSize = true;
			this->checkBoxShowLoginPassword->Location = System::Drawing::Point(154, 203);
			this->checkBoxShowLoginPassword->Name = L"checkBoxShowLoginPassword";
			this->checkBoxShowLoginPassword->Size = System::Drawing::Size(15, 14);
			this->checkBoxShowLoginPassword->TabIndex = 106;
			this->checkBoxShowLoginPassword->UseVisualStyleBackColor = true;
			this->checkBoxShowLoginPassword->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxShowLoginPassword_CheckedChanged);
			// 
			// textBoxSponsor
			// 
			this->textBoxSponsor->Location = System::Drawing::Point(713, 13);
			this->textBoxSponsor->Name = L"textBoxSponsor";
			this->textBoxSponsor->Size = System::Drawing::Size(83, 20);
			this->textBoxSponsor->TabIndex = 107;
			this->textBoxSponsor->Text = L"pulse-sports.ru";
			// 
			// labelSponsor
			// 
			this->labelSponsor->AutoSize = true;
			this->labelSponsor->Location = System::Drawing::Point(661, 16);
			this->labelSponsor->Name = L"labelSponsor";
			this->labelSponsor->Size = System::Drawing::Size(46, 13);
			this->labelSponsor->TabIndex = 108;
			this->labelSponsor->Text = L"Sponsor";
			// 
			// checkBoxNumberOfFinishedLaps
			// 
			this->checkBoxNumberOfFinishedLaps->AutoSize = true;
			this->checkBoxNumberOfFinishedLaps->Checked = true;
			this->checkBoxNumberOfFinishedLaps->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxNumberOfFinishedLaps->Location = System::Drawing::Point(580, 486);
			this->checkBoxNumberOfFinishedLaps->Name = L"checkBoxNumberOfFinishedLaps";
			this->checkBoxNumberOfFinishedLaps->Size = System::Drawing::Size(49, 17);
			this->checkBoxNumberOfFinishedLaps->TabIndex = 110;
			this->checkBoxNumberOfFinishedLaps->Text = L"Laps";
			this->checkBoxNumberOfFinishedLaps->UseVisualStyleBackColor = true;
			// 
			// checkBoxLapsDifference
			// 
			this->checkBoxLapsDifference->AutoSize = true;
			this->checkBoxLapsDifference->Location = System::Drawing::Point(324, 178);
			this->checkBoxLapsDifference->Name = L"checkBoxLapsDifference";
			this->checkBoxLapsDifference->Size = System::Drawing::Size(91, 17);
			this->checkBoxLapsDifference->TabIndex = 111;
			this->checkBoxLapsDifference->Text = L"Laps Differ(%)";
			this->checkBoxLapsDifference->UseVisualStyleBackColor = true;
			this->checkBoxLapsDifference->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxLapsDifference_CheckedChanged);
			// 
			// maskedTextBoxLapsDifference
			// 
			this->maskedTextBoxLapsDifference->Location = System::Drawing::Point(410, 176);
			this->maskedTextBoxLapsDifference->Mask = L"00000";
			this->maskedTextBoxLapsDifference->Name = L"maskedTextBoxLapsDifference";
			this->maskedTextBoxLapsDifference->Size = System::Drawing::Size(27, 20);
			this->maskedTextBoxLapsDifference->TabIndex = 112;
			this->maskedTextBoxLapsDifference->ValidatingType = System::Int32::typeid;
			// 
			// checkBoxHideEmptyColumns
			// 
			this->checkBoxHideEmptyColumns->AutoSize = true;
			this->checkBoxHideEmptyColumns->Location = System::Drawing::Point(742, 463);
			this->checkBoxHideEmptyColumns->Name = L"checkBoxHideEmptyColumns";
			this->checkBoxHideEmptyColumns->Size = System::Drawing::Size(80, 17);
			this->checkBoxHideEmptyColumns->TabIndex = 113;
			this->checkBoxHideEmptyColumns->Text = L"Hide Empty";
			this->checkBoxHideEmptyColumns->UseVisualStyleBackColor = true;
			// 
			// labelStartList
			// 
			this->labelStartList->AutoSize = true;
			this->labelStartList->Location = System::Drawing::Point(100, 13);
			this->labelStartList->Name = L"labelStartList";
			this->labelStartList->Size = System::Drawing::Size(48, 13);
			this->labelStartList->TabIndex = 114;
			this->labelStartList->Text = L"Start List";
			// 
			// labelGroupsTimes
			// 
			this->labelGroupsTimes->AutoSize = true;
			this->labelGroupsTimes->Location = System::Drawing::Point(81, 42);
			this->labelGroupsTimes->Name = L"labelGroupsTimes";
			this->labelGroupsTimes->Size = System::Drawing::Size(72, 13);
			this->labelGroupsTimes->TabIndex = 115;
			this->labelGroupsTimes->Text = L"Groups Times";
			this->labelGroupsTimes->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// labelResultTimes
			// 
			this->labelResultTimes->AutoSize = true;
			this->labelResultTimes->Location = System::Drawing::Point(82, 71);
			this->labelResultTimes->Name = L"labelResultTimes";
			this->labelResultTimes->Size = System::Drawing::Size(68, 13);
			this->labelResultTimes->TabIndex = 116;
			this->labelResultTimes->Text = L"Result Times";
			// 
			// labelRemotePointsDownload
			// 
			this->labelRemotePointsDownload->AutoSize = true;
			this->labelRemotePointsDownload->Location = System::Drawing::Point(82, 203);
			this->labelRemotePointsDownload->Name = L"labelRemotePointsDownload";
			this->labelRemotePointsDownload->Size = System::Drawing::Size(76, 13);
			this->labelRemotePointsDownload->TabIndex = 119;
			this->labelRemotePointsDownload->Text = L"Remote Points";
			// 
			// comboBoxStartListAction
			// 
			this->comboBoxStartListAction->FormattingEnabled = true;
			this->comboBoxStartListAction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"None", L"Download", L"Merge", L"Merge+Remove"});
			this->comboBoxStartListAction->Location = System::Drawing::Point(-2, 10);
			this->comboBoxStartListAction->Name = L"comboBoxStartListAction";
			this->comboBoxStartListAction->Size = System::Drawing::Size(87, 21);
			this->comboBoxStartListAction->TabIndex = 120;
			this->comboBoxStartListAction->Text = L"None";
			this->comboBoxStartListAction->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxStartListAction_SelectedIndexChanged);
			// 
			// comboBoxGroupsTimesAction
			// 
			this->comboBoxGroupsTimesAction->FormattingEnabled = true;
			this->comboBoxGroupsTimesAction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"None", L"Download", L"Merge", 
				L"Merge+Remove"});
			this->comboBoxGroupsTimesAction->Location = System::Drawing::Point(-2, 39);
			this->comboBoxGroupsTimesAction->Name = L"comboBoxGroupsTimesAction";
			this->comboBoxGroupsTimesAction->Size = System::Drawing::Size(87, 21);
			this->comboBoxGroupsTimesAction->TabIndex = 120;
			this->comboBoxGroupsTimesAction->Text = L"None";
			this->comboBoxGroupsTimesAction->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxGroupsTimesAction_SelectedIndexChanged);
			// 
			// comboBoxResultTimesAction
			// 
			this->comboBoxResultTimesAction->FormattingEnabled = true;
			this->comboBoxResultTimesAction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"None", L"Download", L"Merge", 
				L"Merge+Remove"});
			this->comboBoxResultTimesAction->Location = System::Drawing::Point(-2, 68);
			this->comboBoxResultTimesAction->Name = L"comboBoxResultTimesAction";
			this->comboBoxResultTimesAction->Size = System::Drawing::Size(87, 21);
			this->comboBoxResultTimesAction->TabIndex = 120;
			this->comboBoxResultTimesAction->Text = L"None";
			this->comboBoxResultTimesAction->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxResultTimesAction_SelectedIndexChanged);
			// 
			// comboBoxRemotePointsAction
			// 
			this->comboBoxRemotePointsAction->FormattingEnabled = true;
			this->comboBoxRemotePointsAction->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"None", L"Download", L"Merge", 
				L"Merge+Remove"});
			this->comboBoxRemotePointsAction->Location = System::Drawing::Point(-2, 200);
			this->comboBoxRemotePointsAction->Name = L"comboBoxRemotePointsAction";
			this->comboBoxRemotePointsAction->Size = System::Drawing::Size(87, 21);
			this->comboBoxRemotePointsAction->TabIndex = 120;
			this->comboBoxRemotePointsAction->Text = L"None";
			this->comboBoxRemotePointsAction->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxRemotePointsAction_SelectedIndexChanged);
			// 
			// labelTimeLimit
			// 
			this->labelTimeLimit->AutoSize = true;
			this->labelTimeLimit->Location = System::Drawing::Point(701, 260);
			this->labelTimeLimit->Name = L"labelTimeLimit";
			this->labelTimeLimit->Size = System::Drawing::Size(103, 13);
			this->labelTimeLimit->TabIndex = 121;
			this->labelTimeLimit->Text = L"Time Limit(seconds):";
			// 
			// textBoxTimeLimit
			// 
			this->textBoxTimeLimit->Location = System::Drawing::Point(701, 283);
			this->textBoxTimeLimit->Name = L"textBoxTimeLimit";
			this->textBoxTimeLimit->Size = System::Drawing::Size(92, 20);
			this->textBoxTimeLimit->TabIndex = 122;
			this->textBoxTimeLimit->Text = L"999999999";
			// 
			// comboBoxStartCheckList
			// 
			this->comboBoxStartCheckList->Enabled = false;
			this->comboBoxStartCheckList->FormattingEnabled = true;
			this->comboBoxStartCheckList->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"None", L"Download", L"Merge", L"Merge+Remove"});
			this->comboBoxStartCheckList->Location = System::Drawing::Point(-2, 155);
			this->comboBoxStartCheckList->Name = L"comboBoxStartCheckList";
			this->comboBoxStartCheckList->Size = System::Drawing::Size(87, 21);
			this->comboBoxStartCheckList->TabIndex = 120;
			this->comboBoxStartCheckList->Text = L"None";
			this->comboBoxStartCheckList->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxRemotePointsAction_SelectedIndexChanged);
			// 
			// checkBoxStartCheckList
			// 
			this->checkBoxStartCheckList->AutoSize = true;
			this->checkBoxStartCheckList->Location = System::Drawing::Point(92, 158);
			this->checkBoxStartCheckList->Name = L"checkBoxStartCheckList";
			this->checkBoxStartCheckList->Size = System::Drawing::Size(104, 17);
			this->checkBoxStartCheckList->TabIndex = 124;
			this->checkBoxStartCheckList->Text = L"Use Start Check";
			this->checkBoxStartCheckList->UseVisualStyleBackColor = true;
			this->checkBoxStartCheckList->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxStartCheckList_CheckedChanged);
			// 
			// maskedTextBoxStartRegistrationPeriod
			// 
			this->maskedTextBoxStartRegistrationPeriod->Enabled = false;
			this->maskedTextBoxStartRegistrationPeriod->Location = System::Drawing::Point(202, 156);
			this->maskedTextBoxStartRegistrationPeriod->Name = L"maskedTextBoxStartRegistrationPeriod";
			this->maskedTextBoxStartRegistrationPeriod->Size = System::Drawing::Size(56, 20);
			this->maskedTextBoxStartRegistrationPeriod->TabIndex = 86;
			this->maskedTextBoxStartRegistrationPeriod->Text = L"0";
			this->maskedTextBoxStartRegistrationPeriod->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBoxRefreshTime_MaskInputRejected);
			// 
			// labelRegistrationPeriod
			// 
			this->labelRegistrationPeriod->AutoSize = true;
			this->labelRegistrationPeriod->Location = System::Drawing::Point(264, 159);
			this->labelRegistrationPeriod->Name = L"labelRegistrationPeriod";
			this->labelRegistrationPeriod->Size = System::Drawing::Size(83, 13);
			this->labelRegistrationPeriod->TabIndex = 108;
			this->labelRegistrationPeriod->Text = L"Reg Period(sec)";
			// 
			// labelBottom
			// 
			this->labelBottom->AutoSize = true;
			this->labelBottom->Location = System::Drawing::Point(661, 234);
			this->labelBottom->Name = L"labelBottom";
			this->labelBottom->Size = System::Drawing::Size(40, 13);
			this->labelBottom->TabIndex = 125;
			this->labelBottom->Text = L"Bottom";
			// 
			// textBoxBottom
			// 
			this->textBoxBottom->Location = System::Drawing::Point(707, 227);
			this->textBoxBottom->Name = L"textBoxBottom";
			this->textBoxBottom->Size = System::Drawing::Size(86, 20);
			this->textBoxBottom->TabIndex = 126;
			// 
			// checkBoxMergeByID
			// 
			this->checkBoxMergeByID->AutoSize = true;
			this->checkBoxMergeByID->Location = System::Drawing::Point(85, 13);
			this->checkBoxMergeByID->Name = L"checkBoxMergeByID";
			this->checkBoxMergeByID->Size = System::Drawing::Size(15, 14);
			this->checkBoxMergeByID->TabIndex = 129;
			this->checkBoxMergeByID->UseVisualStyleBackColor = true;
			// 
			// comboBoxRaceType
			// 
			this->comboBoxRaceType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxRaceType->FormattingEnabled = true;
			this->comboBoxRaceType->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Mass Start or Splitted Start", L"Mass Start or Splitted Start with Spiridonov\'s coefficients", 
				L"Eliminator Qualification", L"Eliminator Finals", L"Custom Start", L"Number of Tries"});
			this->comboBoxRaceType->Location = System::Drawing::Point(217, 542);
			this->comboBoxRaceType->Name = L"comboBoxRaceType";
			this->comboBoxRaceType->Size = System::Drawing::Size(182, 21);
			this->comboBoxRaceType->TabIndex = 131;
			this->comboBoxRaceType->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxRaceType_SelectedIndexChanged);
			// 
			// labelRaceType
			// 
			this->labelRaceType->AutoSize = true;
			this->labelRaceType->Location = System::Drawing::Point(151, 545);
			this->labelRaceType->Name = L"labelRaceType";
			this->labelRaceType->Size = System::Drawing::Size(60, 13);
			this->labelRaceType->TabIndex = 132;
			this->labelRaceType->Text = L"Race Type";
			// 
			// labelLapName
			// 
			this->labelLapName->AutoSize = true;
			this->labelLapName->Location = System::Drawing::Point(465, 312);
			this->labelLapName->Name = L"labelLapName";
			this->labelLapName->Size = System::Drawing::Size(56, 13);
			this->labelLapName->TabIndex = 133;
			this->labelLapName->Text = L"Lap Name";
			// 
			// textBoxLapName
			// 
			this->textBoxLapName->Location = System::Drawing::Point(527, 309);
			this->textBoxLapName->Name = L"textBoxLapName";
			this->textBoxLapName->Size = System::Drawing::Size(97, 20);
			this->textBoxLapName->TabIndex = 134;
			this->textBoxLapName->Text = L"Круга";
			// 
			// labelLapAdditional
			// 
			this->labelLapAdditional->AutoSize = true;
			this->labelLapAdditional->Location = System::Drawing::Point(447, 337);
			this->labelLapAdditional->Name = L"labelLapAdditional";
			this->labelLapAdditional->Size = System::Drawing::Size(74, 13);
			this->labelLapAdditional->TabIndex = 135;
			this->labelLapAdditional->Text = L"Lap Additional";
			// 
			// textBoxLapAdditionalInfo
			// 
			this->textBoxLapAdditionalInfo->Location = System::Drawing::Point(524, 334);
			this->textBoxLapAdditionalInfo->Name = L"textBoxLapAdditionalInfo";
			this->textBoxLapAdditionalInfo->Size = System::Drawing::Size(100, 20);
			this->textBoxLapAdditionalInfo->TabIndex = 136;
			this->textBoxLapAdditionalInfo->Text = L"Время Финиша Круга";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(819, 561);
			this->Controls->Add(this->textBoxLapAdditionalInfo);
			this->Controls->Add(this->labelLapAdditional);
			this->Controls->Add(this->textBoxLapName);
			this->Controls->Add(this->labelLapName);
			this->Controls->Add(this->labelRaceType);
			this->Controls->Add(this->comboBoxRaceType);
			this->Controls->Add(this->checkBoxMergeByID);
			this->Controls->Add(this->textBoxBottom);
			this->Controls->Add(this->labelBottom);
			this->Controls->Add(this->checkBoxStartCheckList);
			this->Controls->Add(this->textBoxTimeLimit);
			this->Controls->Add(this->labelTimeLimit);
			this->Controls->Add(this->comboBoxStartCheckList);
			this->Controls->Add(this->comboBoxRemotePointsAction);
			this->Controls->Add(this->comboBoxResultTimesAction);
			this->Controls->Add(this->comboBoxGroupsTimesAction);
			this->Controls->Add(this->comboBoxStartListAction);
			this->Controls->Add(this->labelRemotePointsDownload);
			this->Controls->Add(this->labelResultTimes);
			this->Controls->Add(this->labelGroupsTimes);
			this->Controls->Add(this->labelStartList);
			this->Controls->Add(this->checkBoxHideEmptyColumns);
			this->Controls->Add(this->maskedTextBoxLapsDifference);
			this->Controls->Add(this->checkBoxLapsDifference);
			this->Controls->Add(this->checkBoxNumberOfFinishedLaps);
			this->Controls->Add(this->labelRegistrationPeriod);
			this->Controls->Add(this->labelSponsor);
			this->Controls->Add(this->textBoxSponsor);
			this->Controls->Add(this->checkBoxShowLoginPassword);
			this->Controls->Add(this->checkBoxUploadAbsolute);
			this->Controls->Add(this->textBoxFTPPassword);
			this->Controls->Add(this->textBoxFTPLogin);
			this->Controls->Add(this->textBoxFTPPath);
			this->Controls->Add(this->checkBoxUploadGroups);
			this->Controls->Add(this->checkBoxAllButtons);
			this->Controls->Add(this->buttonRemotePoints);
			this->Controls->Add(this->labelRemotePoints);
			this->Controls->Add(this->textBoxRemotePoints);
			this->Controls->Add(this->textBoxRemotePointsNumber);
			this->Controls->Add(this->checkBoxButtons);
			this->Controls->Add(this->textBoxTimeShift);
			this->Controls->Add(this->checkBoxTimeShift);
			this->Controls->Add(this->buttonSaveRaceInfo);
			this->Controls->Add(this->checkBoxRefresh);
			this->Controls->Add(this->maskedTextBoxStartRegistrationPeriod);
			this->Controls->Add(this->maskedTextBoxRefreshTime);
			this->Controls->Add(this->buttonRefreshTimeSubmit);
			this->Controls->Add(this->textBoxAdditonalInfo);
			this->Controls->Add(this->checkBoxAdditionalInfo);
			this->Controls->Add(this->checkBoxErrAndWrnOnly);
			this->Controls->Add(this->checkBoxPrintDSQ);
			this->Controls->Add(this->checkBoxPrintDNS);
			this->Controls->Add(this->labelSecretary);
			this->Controls->Add(this->labelRefereeText);
			this->Controls->Add(this->textBoxSecretary);
			this->Controls->Add(this->textBoxReferee);
			this->Controls->Add(this->checkBoxTimeDifference);
			this->Controls->Add(this->checkBoxLapFinnish);
			this->Controls->Add(this->textBoxGroup);
			this->Controls->Add(this->textBoxTeam);
			this->Controls->Add(this->textBoxPlace);
			this->Controls->Add(this->textBoxCity);
			this->Controls->Add(this->textBoxAge);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->checkBoxPrintDNF);
			this->Controls->Add(this->checkBoxStratch);
			this->Controls->Add(this->checkBoxShowPlace);
			this->Controls->Add(this->checkBoxShowGroup);
			this->Controls->Add(this->checkBoxShowFinishTime);
			this->Controls->Add(this->checkBoxShowLapTimes);
			this->Controls->Add(this->checkBoxShowCity);
			this->Controls->Add(this->checkBoxShowTeam);
			this->Controls->Add(this->checkBoxShowAge);
			this->Controls->Add(this->checkBoxShowName);
			this->Controls->Add(this->checkBoxShowID);
			this->Controls->Add(this->labelNumberOfSignsAfterPoint);
			this->Controls->Add(this->textBoxNumberOfSignsAfterPoint);
			this->Controls->Add(this->buttonLoadRaceInfoData);
			this->Controls->Add(this->checkBoxUseInterfaceLogger);
			this->Controls->Add(this->textBoxMinimalTimeForLap);
			this->Controls->Add(this->labelMinimalTimeForLap);
			this->Controls->Add(this->textBoxTrackConditions);
			this->Controls->Add(this->labelTrackConditions);
			this->Controls->Add(this->textBoxOrganizator);
			this->Controls->Add(this->labelOrganizator);
			this->Controls->Add(this->labelAdditionalReferee);
			this->Controls->Add(this->labelMainReferee);
			this->Controls->Add(this->textBoxAdditionalReferee);
			this->Controls->Add(this->textBoxMainReferee);
			this->Controls->Add(this->textBoxWeather);
			this->Controls->Add(this->textBoxRacePlace);
			this->Controls->Add(this->textBoxRaceDate);
			this->Controls->Add(this->textBoxRaceName);
			this->Controls->Add(this->labelWeather);
			this->Controls->Add(this->labelRacePlace);
			this->Controls->Add(this->labelRaceDate);
			this->Controls->Add(this->labelRaceName);
			this->Controls->Add(this->labelLogSearch);
			this->Controls->Add(this->buttonLogSearch);
			this->Controls->Add(this->textBoxLogSearch);
			this->Controls->Add(this->labelLoggerInfo);
			this->Controls->Add(this->listBoxLogger);
			this->Controls->Add(this->checkBoxUseFileLogger);
			this->Controls->Add(this->checkBoxDisableDSQ);
			this->Controls->Add(this->checkBoxDisableDNF);
			this->Controls->Add(this->buttonAbsoluteProtocol);
			this->Controls->Add(this->textBoAbsoluteProtocol);
			this->Controls->Add(this->buttonGenerateProtocol);
			this->Controls->Add(this->textBoxGroupsProtocol);
			this->Controls->Add(this->textBoxFinishTime);
			this->Controls->Add(this->textBoxGroupTime);
			this->Controls->Add(this->textBoxStartProtocol);
			this->Controls->Add(this->buttonGroupsProtocol);
			this->Controls->Add(this->buttonFinishTime);
			this->Controls->Add(this->buttonGroupTime);
			this->Controls->Add(this->buttonStartProtocol);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Finish Protocol Generator (pulse-sports.ru)";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: char* getCharArrayFromString(String^ inputString) {
					return LoggerSTC::getCharArrayFromString(inputString);
		 }



	private: System::Void buttonResultsFile_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ resultFileDialog = gcnew SaveFileDialog();
			 resultFileDialog->RestoreDirectory = true;
			 resultFileDialog->ShowDialog();
			 if(resultFileDialog->FileName != String::Empty) {
				 textBoxGroupsProtocol->Text = resultFileDialog->FileName;
			 }
		 }
private: System::Void buttonLogFile_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void buttonFinishTime_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ finishTimeFileDialog = gcnew OpenFileDialog();
			 finishTimeFileDialog->RestoreDirectory = true;
			 finishTimeFileDialog->ShowDialog();
			 if(finishTimeFileDialog->FileName != String::Empty) {
				 textBoxFinishTime->Text = finishTimeFileDialog->FileName;
			 }
		 }
private: System::Void buttonGroupTime_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ groupTimeFileDialog = gcnew OpenFileDialog();
			 groupTimeFileDialog->RestoreDirectory = true;
			 groupTimeFileDialog->ShowDialog();
			 if(groupTimeFileDialog->FileName != String::Empty) {
				 textBoxGroupTime->Text = groupTimeFileDialog->FileName;
			 }
		 }
private: System::Void buttonStartProtocol_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ startProtocolFileDialog = gcnew OpenFileDialog();
			 startProtocolFileDialog->RestoreDirectory = true;
			 startProtocolFileDialog->ShowDialog();
			 if(startProtocolFileDialog->FileName != String::Empty) {
				 textBoxStartProtocol->Text = startProtocolFileDialog->FileName;
			 }
		 }

				  
		 private: void readStartProtocolStructure() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readStartProtocolStructure()"));
					  numberOfStartProtocolElements = 0;
					  startProtocolList = new StartProtocolElement*[arraysVolume];
					  char* tempString = new char[LoggerSTC::numberOfCharsInString];
					  for (int i =0; i<arraysVolume;i++) {
						  if(readStringFromFile(startProtocolFile, tempString)!=EOF) {
							  startProtocolList[i] = new StartProtocolElement(tempString,currentParser, skipFirstLap(), isEliminatorFinals());
							  numberOfStartProtocolElements++;
							  bool groupAlreadyExists = false;
							  if(isEliminatorFinals()) { 
								  for(int groupsEliminatorCounter = 0;groupsEliminatorCounter< numberOfEliminatorGroups;groupsEliminatorCounter++) {
									  if(strcmp(groupEliminatorList[groupsEliminatorCounter]->groupID, startProtocolList[i]->groupID) == 0) {
										  groupAlreadyExists = true;
										  break;
									  }
								  }
							  } else {
								  for(int groupsCounter = 0;groupsCounter < numberOfGroups;groupsCounter++) {
									  if(strcmp(groupStartList[groupsCounter]->groupID, startProtocolList[i]->groupID) == 0) {
										  groupAlreadyExists = true;
										  break;
									  }
								  }
							  }
							  if(!groupAlreadyExists) {
								  if(isEliminatorFinals()) {
									  addEliminatorGroup(startProtocolList[i]->groupID);
								  } else {
									  groupStartList[numberOfGroups] = 
										  new GroupStartElement(startProtocolList[i]->groupID, 0.0);
									  numberOfGroups++;
								  }
							  }
						  } else {
							  break;
						  }
					  }
					  delete tempString;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readStartProtocolStructure()"));
				  }
		 private: void readGroupTimeStructure() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readGroupTimeStructure()"));
					  numberOfGroups = 0;
					  groupStartList = new GroupStartElement*[arraysVolume];
					  char* tempString = new char[LoggerSTC::numberOfCharsInString];
					  for (int i =0; i<arraysVolume;i++) {
						  if(readStringFromFile(groupsStartTimeFile, tempString)!=EOF) {
							  groupStartList[i] = new GroupStartElement(tempString,currentParser);
							  numberOfGroups++;
						  } else {
							  break;
						  }
					  }
					  delete tempString;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readGroupTimeStructure()"));
				  }
		private: void readRemotePointsStructure(int j) {
					 LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readRemotePointsStructure(int i): ") + j.ToString());
					 numberOfRemoteElements[j] = 0;
					 remotePointsList[j] = new FinishCompetitorElement*[arraysVolume];
					 char* tempString = new char[LoggerSTC::numberOfCharsInString];
					 for (int i =0; i<arraysVolume;i++) {
						if(readStringFromFile(remoteTimeFile, tempString)!=EOF) {
							remotePointsList[j][i] = new FinishCompetitorElement(tempString,currentParser);
							numberOfRemoteElements[j]++;

						} else {
							break;
						}
					 }
					 delete tempString;
					 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readRemotePointsStructure(int i)"));

				 }
		 private: void readFinishTimeStructure() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readFinishTimeStructure()"));
					  numberOfCompetitorElements = 0;
					  finishCompetitorList = new FinishCompetitorElement*[arraysVolume];
					  char* tempString = new char[LoggerSTC::numberOfCharsInString];
					  for (int i =0; i<arraysVolume;i++) {
						  if(readStringFromFile(finishTimeFile, tempString)!=EOF) {
							  finishCompetitorList[i] = new FinishCompetitorElement(tempString,currentParser);
							  numberOfCompetitorElements++;
						  } else {
							  break;
						  }
					  }
					  delete tempString;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readFinishTimeStructure()"));
				  }
				 private: void readStartCheckList() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readStartCheckList()"));
					  numberOfStartChecks = 0;
					  startCheckList = new FinishCompetitorElement*[arraysVolume];
					  char* tempString = new char[LoggerSTC::numberOfCharsInString];
					  for (int i =0; i<arraysVolume;i++) {
						  if(readStringFromFile(startCheckListFile, tempString)!=EOF) {
							  startCheckList[i] = new FinishCompetitorElement(tempString,currentParser);
							  numberOfStartChecks++;
						  } else {
							  break;
						  }
					  }
					  delete tempString;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readStartCheckList()"));
						  }

private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
 					 if(MessageBox::Show("Are you sure to exit?","Warning!",MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::Yes) {
						 buttonSaveRaceInfo_Click(sender,e);
					 } else {
						 e->Cancel = true;

					 }
		 }
		 private: int readFilesData(double eliminationCoefficient) {
						 if((groupsStartTimeFile = fopen(getCharArrayFromString(textBoxGroupTime->Text),"r+"))==NULL) {
							 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open groupsStartFile: ") + textBoxGroupTime->Text);
							 return -1;
						 } else {
 							 if(isEliminatorFinals()) {
								 readGroupsEliminatorData(eliminationCoefficient);
							 } else {
								 readGroupTimeStructure();
							 }
						 }
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readFilesData()"));
				 if((startProtocolFile = fopen(getCharArrayFromString(textBoxStartProtocol->Text),"r+"))==NULL) {
					 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open startProtocolFile: ") + textBoxStartProtocol->Text);
					 return -1;
				 } else {
					 readStartProtocolStructure();
				 }
				 if((finishTimeFile = fopen(getCharArrayFromString(textBoxFinishTime->Text),"r+"))==NULL) {
					 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open finishTimesFile: ") + textBoxFinishTime->Text);
					 return -1;
				 } else {
 					  if(isEliminatorFinals()) {
						  readEliminatorFinishesData();
					  } else {
							 readFinishTimeStructure();
					  }
				 }
				  if(!isEliminatorFinals()) {
					 numberOfPoints = ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxRemotePointsNumber->Text));
					 columnsNumber = numberOfPoints+1;
					 rowsNumber = 1 + ((numberOfPoints>0 && !isNumberOfTries() && checkBoxShowLapTimes->Checked)?1:0) + ((checkBoxAllButtons->Checked && checkBoxShowLapTimes->Checked)?1:0);
					 numberOfRemoteElements = new int[numberOfPoints];
					 remotePointsList = new FinishCompetitorElement**[numberOfPoints];
					 for(int i = 1; i<=numberOfPoints;i++) {
						 if((remoteTimeFile = fopen(getCharArrayFromString(textBoxRemotePoints->Text + "results_" + i.ToString() + ".txt"),"r+"))==NULL) {
							LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open one of remoteTimeFiles: ") + textBoxRemotePoints->Text + "results_" + i.ToString() + ".txt");
							return -1;
						 } else {
							readRemotePointsStructure(i-1);
							fclose(remoteTimeFile);
						 }
					 }
					 if(checkBoxStartCheckList->Checked) {
						 if((startCheckListFile = fopen(getCharArrayFromString(checkListFileName),"r+"))==NULL) {
							 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open startCheckListFile: ") + checkListFileName);
						 } else {
							 readStartCheckList();
							 fclose(startCheckListFile);
						 }
					 }
				  }
					 fclose(startProtocolFile);
					 fclose(groupsStartTimeFile);
					 fclose(finishTimeFile);
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readFilesData()"));
					 return 1;
		 }
		 private: int openOutputFiles() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Open Output files"));

				 if((groupProtocolFile = fopen(getCharArrayFromString(textBoxGroupsProtocol->Text),"w+"))==NULL) {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open groupProtocolFile"));
				    return -1;
				 }
				 if(!isEliminatorFinals()) {
					 if((absoluteProtocolFile = fopen(getCharArrayFromString(textBoAbsoluteProtocol->Text),"w+"))==NULL) {
						  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open absoluteProtocolFile"));
						  fclose(groupProtocolFile);
						 return -1;
					 }
					 if(generateTextFinishProtocol()) {
						 if((groupProtocolFileText = fopen(getCharArrayFromString(textBoxGroupsProtocol->Text + gcnew String(".txt")),"w+"))==NULL) {
							  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open groupProtocolFileText"));
							return -1;
						 }
					 }
				 }
				 LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Output files opened successfully"));
				 return 1;
		 }
		 private: void closeOutputFiles() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function closeOutputFiles()"));
					  try {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String("Close group protocol file"));
						  fclose(groupProtocolFile);
		  			 } catch (Object^ e) {
						 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Some error during group protocol close: ") + e->ToString());
					 }
					  if(!isEliminatorFinals()) {
	  					 if(generateTextFinishProtocol()) {
							  try {
								 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String("Close TEXT group protocol file"));
								  fclose(groupProtocolFileText);
		  					 } catch (Object^ e) {
								 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Some error during TEXT group protocol close: ") + e->ToString());
							 }
						 }

						  try {
							 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO, gcnew String("Close group protocol file"));
							 fclose(absoluteProtocolFile);
		  				 } catch (Object^ e) {
							 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Some error during group protocol close: ") + e->ToString());
						 }
					  }
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function closeOutputFiles()"));
		 }
			private: bool firstResultBetterThanSecond(FinishProtocolElement* firstResult, FinishProtocolElement* secondResult) {
//						 if(strcmp(firstResult->competitorID,secondResult->competitorID)==0) {
//							 return false;
//						 }
						 if(!firstResult->disqualified && secondResult->disqualified) {
							 return true;
						 }
						 if(firstResult->disqualified && !secondResult->disqualified) {
							 return false;
						 }
						 if(firstResult->finished && !secondResult->finished) {
							 return true;
						 }
						 if(!firstResult->finished && secondResult->finished) {
							 return false;
						 }
						 if(isNumberOfTries()) {
							 if(firstResult->getNumberOfSuccessfullyFinishedTries(false) != secondResult->getNumberOfSuccessfullyFinishedTries(false)) {
								 return (firstResult->getNumberOfSuccessfullyFinishedTries(false) > secondResult->getNumberOfSuccessfullyFinishedTries(false));
							 }
							 return firstResult->getTotalTime(false) < secondResult->getTotalTime(false);
						 }
						 if(firstResult->numberOfLapsFinished != secondResult->numberOfLapsFinished) {
							 return (firstResult->numberOfLapsFinished > secondResult->numberOfLapsFinished);
						 }
						 int cpCounterFirst = 0;
						 int cpCounterSecond = 0;
						 if(firstResult->numberOfLapsFinished+1 <= firstResult->numberOfLaps) {
							 for(;cpCounterFirst < numberOfPoints;cpCounterFirst++) {
								 if(firstResult->controlPoints[firstResult->numberOfLapsFinished]->segmentFinishes[cpCounterFirst] == -1) {
									 break;
								 }
							 }
						 }
						 if(secondResult->numberOfLapsFinished+1 <= secondResult->numberOfLaps) {
							 for(;cpCounterSecond < numberOfPoints;cpCounterSecond++) {
								 if(secondResult->controlPoints[firstResult->numberOfLapsFinished]->segmentFinishes[cpCounterSecond] == -1) {
									 break;
								 }
							 }
						 }
						 if(firstResult->numberOfLapsFinished == 0 && secondResult->numberOfLapsFinished == 0 && cpCounterFirst == 0 && cpCounterSecond == 0 && firstResult->startDelay != secondResult->startDelay) {
								return (firstResult->startDelay < secondResult->startDelay);
						 }
						 if(skipFirstLap()) {
							 if(firstResult->crossLineTimes[0]==double::MaxValue && secondResult->crossLineTimes[0]!=double::MaxValue) {
								 return false;
							 }
							 if(firstResult->crossLineTimes[0]!=double::MaxValue && secondResult->crossLineTimes[0]==double::MaxValue) {
								 return true;
							 }
						 }
						 if(firstResult->numberOfLapsFinished == 0 && secondResult->numberOfLapsFinished == 0 && cpCounterFirst == 0 && cpCounterSecond == 0) {
							 if(strlen(firstResult->competitorID)==strlen(secondResult->competitorID)) {
								return (strcmp(firstResult->competitorID,secondResult->competitorID)<0);
							 } else {
								 return(strlen(firstResult->competitorID)<strlen(secondResult->competitorID));
							 }
						 }
						 if(cpCounterFirst != cpCounterSecond) {
							 return (cpCounterFirst > cpCounterSecond);
						 }
						 if(cpCounterFirst == 0) {
							 return (firstResult->finishLapTimes[firstResult->numberOfLapsFinished-1]<secondResult->finishLapTimes[secondResult->numberOfLapsFinished-1]);
						 }
						 double previuosLapTimeFirst = (firstResult->numberOfLapsFinished==0)?0:firstResult->finishLapTimes[firstResult->numberOfLapsFinished-1];
						 double previuosLapTimeSecond = (firstResult->numberOfLapsFinished==0)?0:secondResult->finishLapTimes[firstResult->numberOfLapsFinished-1];
						 return (previuosLapTimeFirst + firstResult->controlPoints[firstResult->numberOfLapsFinished]->segmentFinishes[cpCounterFirst-1] < previuosLapTimeSecond + secondResult->controlPoints[firstResult->numberOfLapsFinished]->segmentFinishes[cpCounterFirst-1]);
					 }
				  private: void generateSortedProtocol() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function \"generateSortedProtocol()\""));
							   finishProtocolListSorted = new FinishProtocolElement*[numberOfFinishProtocolElements];
							   for(int i = 0;i<numberOfFinishProtocolElements;i++) {
								  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Find first not sorted athlete"));
								   for(int j = 0;j<numberOfFinishProtocolElements;j++) {
									   if(!finishProtocolList[j]->sorted) {
										  finishProtocolListSorted[i] = finishProtocolList[j];
										  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("First not sorted athlete successfully found"));
										  break;
									   }
								   }
								  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Find the best not sorted athlete"));
								  for(int finishProtocolCounter = 0;finishProtocolCounter<numberOfFinishProtocolElements;finishProtocolCounter++) {
									  if(!finishProtocolList[finishProtocolCounter]->sorted && firstResultBetterThanSecond(finishProtocolList[finishProtocolCounter], finishProtocolListSorted[i])) {
										  finishProtocolListSorted[i] = finishProtocolList[finishProtocolCounter];
									  }
								  }
								  finishProtocolListSorted[i]->sorted = true;
								  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("The best not sorted athlete successfully found. His id is \"") + gcnew String(finishProtocolListSorted[i]->competitorID) + gcnew String("\""));
							   }
						   LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function \"generateSortedProtocol()\""));
						   }

						   private: double spiridonov(char* yearOfBirth) {
										time_t theTime = time(NULL);
										struct tm *aTime = localtime(&theTime);

										double birthYear = ProtocolStringParser::getIntByString(yearOfBirth);
										double currentYear = aTime->tm_year + 1900;
										return ((0.02266 * (currentYear-birthYear)*(currentYear-birthYear) - 1.25437 * (currentYear-birthYear) + 117.37067 ) /100);
									}



						   private: System::Void clearMemory() {
								   LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Clear startProtocolList"));
										for(int i = 0;i<numberOfStartProtocolElements;i++) {
											delete startProtocolList[i];
										}
										if(!isEliminatorFinals()){
										   LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function \"clearMemory()\""));
											   LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Clear finishCompetitorList"));
													for(int i = 0;i<numberOfCompetitorElements;i++) {
														delete finishCompetitorList[i];
													}
											   LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Clear numberOfRemoteElements"));
													for(int i = 0;i<numberOfPoints;i++) {
														for(int j = 0;j<numberOfRemoteElements[i];j++) {
															delete remotePointsList[i][j];
														}
														delete remotePointsList[i];
													}

											   LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Clear groupStartList"));
													for(int j = 0;j<numberOfGroups;j++) {
			//											LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Clear groupStartList ") + j.ToString());
														delete groupStartList[j];
													}
			//										for(int l = 0;l<numberOfStartProtocolElements;l++) {
			//											delete finishProtocolList[l];
			//										}
											   LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Clear structures"));
													delete remotePointsList;
													delete finishCompetitorList;
													delete startProtocolList;
													delete groupStartList;
													delete finishProtocolList;
													delete finishProtocolListSorted;
										}
									   LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function \"clearMemory()\""));
									}

									private: int mergeFiles(String^ toFileName, String^ fromFileName, bool mergeByID) {
												 FILE* fromFile;
												 FILE* toFile;
												 int toFileStrings = 0;
												  char** toFileVolume = new char*[arraysVolume];
												  char* tempString = new char[LoggerSTC::numberOfCharsInString];
												 if((fromFile = fopen(getCharArrayFromString(fromFileName),"r+"))==NULL) {
													 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open file (read): ") + fromFileName);
													 return -1;
												 }
												 int fromFileStrings = 0;
												  char** fromFileVolume = new char*[arraysVolume];
												  for (fromFileStrings=0; fromFileStrings<arraysVolume;fromFileStrings++) {
													  if(readStringFromFile(fromFile, tempString)!=EOF) {
														  fromFileVolume[fromFileStrings] = tempString;
														  tempString = new char[LoggerSTC::numberOfCharsInString];
													  } else {
														  break;
													  }
												  }
												  fclose(fromFile);

												 if((toFile = fopen(getCharArrayFromString(toFileName),"r+"))==NULL) {
													 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open file (read): ") + toFileName);
												 } else {
													  for (toFileStrings=0; toFileStrings<arraysVolume;toFileStrings++) {
														  if(readStringFromFile(toFile, tempString)!=EOF) {
															  toFileVolume[toFileStrings] = tempString;
															  tempString = new char[LoggerSTC::numberOfCharsInString];
														  } else {
															  break;
														  }
													  }
													  fclose(toFile);
												 }
												 if((toFile = fopen(getCharArrayFromString(toFileName),"w"))==NULL) {
													 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Unable to open file (write): ") + toFileName);
													 return -1;
												 }
												 for(int j = 0;j<toFileStrings;j++) {
													 bool stringFound = false;
													 for(int i = j+1;i<toFileStrings;i++) {
														 if(similarStrings(toFileVolume[j], toFileVolume[i], mergeByID)) {
															 stringFound = true;
															 break;
														 }
													 }
													 if(!stringFound) {
														 for(int i = 0;i<fromFileStrings;i++) {
															 if(similarStrings(toFileVolume[j], fromFileVolume[i], mergeByID)) {
																 stringFound = true;
																 break;
															 }
														 }
													 }
													 if(!stringFound) {
														 writeStringToFile(toFile, toFileVolume[j],true);
													 }
												 }
												 for(int i = 0;i<fromFileStrings;i++) {
													 bool stringFound = false;
													 for(int j = i+1;j<fromFileStrings;j++) {
														 if(similarStrings(fromFileVolume[j], fromFileVolume[i], mergeByID)) {
															 stringFound = true;
															 break;
														 }
													 }
													 if(!stringFound) {
														 writeStringToFile(toFile, fromFileVolume[i],true);
													 }
												 }
												 fclose(toFile);
												 delete toFile;
												 delete fromFile;
												 for(int i = 0;i< toFileStrings;i++) {
													 delete toFileVolume[i];
												 }
												 for(int j = 0;j<fromFileStrings;j++) {
													 delete fromFileVolume[j];
												 }
												 delete toFileVolume;
												 delete fromFileVolume;
												 return 0;
											 }
											 private: bool similarStrings(char* firstString, char* secondString, bool onlyID) {
														  if(!onlyID) {
															  return (strcmp(firstString, secondString)==0);
														  } else {
															  return (strcmp(ProtocolStringParser::getFieldByNumber(firstString, 0, currentParser),
																  ProtocolStringParser::getFieldByNumber(secondString, 0, currentParser))==0);
														  }
													  }
									private: int downloadFile(WebClient^ myWebClient, String^ addressFTP, String^ localFilePath, bool doMerge, bool doRemove, bool mergeByID) {
												 String^ downloadFileName = localFilePath->Substring(localFilePath->LastIndexOf("\\")+1);
												 String^ tmsSuffix = gcnew String(".tmp");

												 try {
													 myWebClient->DownloadFile( addressFTP + downloadFileName, localFilePath + (doMerge? gcnew String(".tmp"):gcnew String("")) );
													 if(doMerge) {
														if(mergeFiles(localFilePath, localFilePath + tmsSuffix, mergeByID) == -1) {
															 return -1;
														}
													}
													 if(doRemove) {
	 													 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Remove ") + addressFTP + downloadFileName);
														FtpWebRequest^ request = dynamic_cast<FtpWebRequest^>(WebRequest::Create( addressFTP + downloadFileName ));
														request->Method = WebRequestMethods::Ftp::DeleteFile;
														request->Credentials = myWebClient->Credentials;
														FtpWebResponse^ response = dynamic_cast<FtpWebResponse^>(request->GetResponse());
													}

													Threading::Thread::Sleep(1000);
												 } catch (Object^ e) {
													 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Downloading of file \"") + localFilePath + gcnew String("\" from \"") + addressFTP + downloadFileName +  gcnew String("\" failed: ")+ e->ToString());
													 return -1;
												 }

												 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Downloading of file \"") + localFilePath + gcnew String("\" from \"") + addressFTP + downloadFileName +  gcnew String("\" successfully completed!"));
												 return 0;


											 }
									private: int uploadFile(WebClient^ myWebClient, String^ localFile, String^ uploadPath) {
												 String^ uploadFileName = localFile->Substring(localFile->LastIndexOf("\\")+1);

												 try {
													 array<Byte>^responseArray = myWebClient->UploadFile( uploadPath + uploadFileName, localFile );
													 Threading::Thread::Sleep(1000);
												 } catch (Object^ e) {
													 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Uploading of file \"") + localFile + gcnew String("\" to \"") + uploadPath + uploadFileName +  gcnew String("\" failed: ")+ e->ToString());
													 return -1;
												 }

												 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Uploading of file \"") + localFile + gcnew String("\" to \"") + uploadPath +  gcnew String("\" successfully completed!"));
												 return 0;
	
									}

private: int downloadFiles() {
			 int returnValue = 0;
			 WebClient^ myWebClient = gcnew WebClient;
			 String^ fileName;
			 myWebClient->Credentials = gcnew NetworkCredential(textBoxFTPLogin->Text, textBoxFTPPassword->Text);
			 if(downloadRequired(comboBoxRemotePointsAction)) {
				 for(int i = 0;i < ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxRemotePointsNumber->Text));i++) {
					 if(downloadFile(myWebClient, textBoxFTPPath->Text,textBoxRemotePoints->Text + gcnew String("results_") + (i+1).ToString() + gcnew String(".txt"),mergeRequired(comboBoxRemotePointsAction), removeRequired(comboBoxRemotePointsAction), false) == -1) {
						 returnValue = -1;
					 }
				 }
			 }
			 
			 if(downloadRequired(comboBoxStartListAction)) {
				 if(downloadFile(myWebClient, textBoxFTPPath->Text,textBoxStartProtocol->Text,mergeRequired(comboBoxStartListAction),removeRequired(comboBoxStartListAction), checkBoxMergeByID->Checked) == -1) {
					 returnValue = -1;
				 }
			 }
			 if(downloadRequired(comboBoxGroupsTimesAction)) {
				 if(downloadFile(myWebClient, textBoxFTPPath->Text,textBoxGroupTime->Text,mergeRequired(comboBoxGroupsTimesAction),removeRequired(comboBoxGroupsTimesAction), false) == -1) {
					 returnValue = -1;
				 }
			 }
			 if(downloadRequired(comboBoxResultTimesAction)) {
				 if(downloadFile(myWebClient, textBoxFTPPath->Text,textBoxFinishTime->Text,mergeRequired(comboBoxResultTimesAction),removeRequired(comboBoxResultTimesAction), false) == -1) {
					 returnValue = -1;
				 }
			 }
			 if(checkBoxStartCheckList->Checked && downloadRequired(comboBoxStartCheckList)) {
				 if(downloadFile(myWebClient, textBoxFTPPath->Text,checkListFileName,mergeRequired(comboBoxStartCheckList),removeRequired(comboBoxStartCheckList), false) == -1) {
					 returnValue = -1;
				 }
			 }
//			 myWebClient->Dispose();

			 delete myWebClient;
			 return returnValue;
		 }
 private: bool downloadRequired(ComboBox^ combik) {
			  return (combik->Text == downloadMerge || combik->Text == downloadReplace || combik->Text == downloadMergeRemove);
		  }
private: bool mergeRequired(ComboBox^ combik) {
			  return (combik->Text == downloadMerge || combik->Text == downloadMergeRemove);
		  }
private: bool removeRequired(ComboBox^ combik) {
			  return (combik->Text == downloadMergeRemove);
		  }

private: int uploadFiles() {
			 WebClient^ myWebClient = gcnew WebClient;
			 myWebClient->Credentials = gcnew NetworkCredential(textBoxFTPLogin->Text, textBoxFTPPassword->Text);

 			 if(checkBoxUploadGroups->Checked) {
				 if(uploadFile(myWebClient,  textBoxGroupsProtocol->Text,textBoxFTPPath->Text) == -1) {
					 return -1;
				 }
			 }
			 if(checkBoxUploadAbsolute->Checked && !isEliminatorFinals()) {
				 if(uploadFile(myWebClient,  textBoAbsoluteProtocol->Text,textBoxFTPPath->Text) == -1) {
					 return -1;
				 }
			 }
//			 myWebClient->di
			 delete myWebClient;
			 return 0;
		 }
		 private: void readGroupsEliminatorData(double eliminationCoefficient){
  					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readGroupsEliminatorData()"));
					  numberOfEliminatorGroups = 0;
					  groupEliminatorList = new GroupEliminator*[arraysVolume];
					  char* tempString = new char[LoggerSTC::numberOfCharsInString];
					  for (int i =0; i<arraysVolume;i++) {
						  if(readStringFromFile(groupsStartTimeFile, tempString)!=EOF) {
							  groupEliminatorList[i] = new GroupEliminator(tempString,currentParser,eliminationCoefficient);
							  numberOfEliminatorGroups++;
						  } else {
							  break;
						  }
					  }
					  delete tempString;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readGroupsEliminatorData()"));
				  }
		 private: void readEliminatorFinishesData(){
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function void readEliminatorFinishesData()"));
					  numberOfFinalRounds = 0;
					  finalRoundsList = new FinalRound*[arraysVolume];
					  char* tempString = new char[LoggerSTC::numberOfCharsInString];
					  for (int i =0; i<arraysVolume;i++) {
						  if(readStringFromFile(finishTimeFile, tempString)!=EOF) {
							  finalRoundsList[i] = new FinalRound(tempString,currentParser);
							  numberOfFinalRounds++;
						  } else {
							  break;
						  }
					  }
					  delete tempString;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function void readEliminatorFinishesData()"));
					  
				  }
		 private: void addEliminatorGroup(char* groupName){
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Method read addEliminatorGroup(char* groupName) not implemented because it's difficult to say what parameters of group you want to add. GroupID:") + gcnew String(groupName));
				  }

				  private:void writeOneFinal(FinalRound* oneFinalRound, int isSmallFinal) {
						  fprintf(groupProtocolFile,"<table style=\"%s\"", getCharArrayFromString(tableStyle));
						  if(checkBoxStratch->Checked) fprintf(groupProtocolFile," width=100%%");
						  fprintf(groupProtocolFile," border=0>");
						  fprintf(groupProtocolFile,"<tr style=\"%s\">", getCharArrayFromString(topLineStyle));
						  if(checkBoxShowPlace->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxPlace->Text));
						  if(checkBoxShowID->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxID->Text));
						  if(checkBoxShowName->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxName->Text));
						  if(checkBoxShowAge->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxAge->Text));
						  if(checkBoxShowTeam->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B><NOBR>%s</NOBR></B></td>\n",getCharArrayFromString(textBoxTeam->Text));
						  if(checkBoxShowCity->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxCity->Text));
						  if(checkBoxAdditionalInfo->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxAdditonalInfo->Text));
						  if(checkBoxTimeShift->Checked) fprintf(groupProtocolFile,"<td ALIGN=center><B>%s</B></td>\n",getCharArrayFromString(textBoxTimeShift->Text));
//						  fprintf(groupProtocolFile,"<td ALIGN=center><B>PreviousPlace</B></td>\n");
						  fprintf(groupProtocolFile,"</tr>\n");
						  for(int placeCounter = 0;placeCounter<oneFinalRound->roundSize;placeCounter++) {
							  bool numberFound = false;
							  int competitorCounter = 0;
							  for(competitorCounter;competitorCounter<numberOfStartProtocolElements;competitorCounter++){
								  if(!oneFinalRound->filledNumbers) {
									  break;
								  }
								  if((oneFinalRound->numbers[placeCounter] != NULL) && 
									  (strcmp(oneFinalRound->numbers[placeCounter],
									  startProtocolList[competitorCounter]->competitorID) == 0)) {
									  numberFound = true;
									  break;
								  }
							  }
							  if(fmod(placeCounter+1.0,2.0) == 0.0) {
								 fprintf(groupProtocolFile,"<tr style=\"%s\">",getCharArrayFromString(oddLineStyle));
							  } else {
								 fprintf(groupProtocolFile,"<tr style=\"%s\">",getCharArrayFromString(evenLineStyle));
							  }
							  if(checkBoxShowPlace->Checked) {
								  if(oneFinalRound->filledResults && oneFinalRound->filledNumbers && oneFinalRound->finishedCompetitors[placeCounter]) {
									  fprintf(groupProtocolFile,"<td ALIGN=center>%d</td>\n",(isSmallFinal + placeCounter+1));
								  } else {
									  fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n",(strcmp(oneFinalRound->numbers[placeCounter],"")==0)?"":"DNF");
								  }
							  }
							  if(checkBoxShowID->Checked) {
								  if((oneFinalRound->numbers[placeCounter] != NULL) && oneFinalRound->filledNumbers) {
									  fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n", oneFinalRound->numbers[placeCounter]);
								  } else {
									  fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
								  }
							  }
							  if(numberFound && oneFinalRound->filledNumbers) {
								  if(checkBoxShowName->Checked) fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n", startProtocolList[competitorCounter]->competitorName);
								  if(checkBoxShowAge->Checked) fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n", startProtocolList[competitorCounter]->competitorYearOfBirth);
								  if(checkBoxShowTeam->Checked) fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n", startProtocolList[competitorCounter]->competitorTeam);
								  if(checkBoxShowCity->Checked) fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n", startProtocolList[competitorCounter]->competitorCity);
								  if(checkBoxAdditionalInfo->Checked) fprintf(groupProtocolFile,"<td ALIGN=center>%s</td>\n",startProtocolList[competitorCounter]->competitorAdditionalInfo);
								  int qualificationPlace = startProtocolList[competitorCounter]->startDelay;
								  if(checkBoxTimeShift->Checked) fprintf(groupProtocolFile,"<td ALIGN=center>%d</td>\n",qualificationPlace);
							  } else {
								  if(oneFinalRound->filledNumbers && strcmp(oneFinalRound->numbers[placeCounter],"") != 0) {
									  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Not Registered competitor with id=") + gcnew String(oneFinalRound->numbers[placeCounter]));
								  }
								  if(checkBoxShowName->Checked) fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
								  if(checkBoxShowAge->Checked) fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
								  if(checkBoxShowTeam->Checked) fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
								  if(checkBoxShowCity->Checked) fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
								  if(checkBoxAdditionalInfo->Checked) fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
								  if(checkBoxTimeShift->Checked) fprintf(groupProtocolFile,"<td ALIGN=center></td>\n");
							  }
//							  fprintf(groupProtocolFile,"<td ALIGN=center>%d</td>\n", oneFinalRound->previousPlaces[placeCounter]);
							  fprintf(groupProtocolFile,"</tr>\n");
						  }
						  fprintf(groupProtocolFile,"</table>\n");
						  }



private: void writeFinalTable(int finalStep,int finalNumber, GroupEliminator* eliminatorGroup, double eliminationCoefficient) {
			 int stageName = pow(eliminationCoefficient, eliminatorGroup->numberOfRounds - finalStep - 1);
			 if(stageName != 1) {
				 fprintf(groupProtocolFile,"<FONT SIZE=\"3\" COLOR=\"#000000\"><B><CENTER> 1/%d финала %d заезд</CENTER></B></FONT>", stageName,finalNumber+1);
			 } else {
				 fprintf(groupProtocolFile,"<FONT SIZE=\"3\" COLOR=\"#000000\"><B><CENTER>%s финал</CENTER></B></FONT>", (finalNumber==0)?"Большой":"Малый");
			 }
			 FinalRound* oneRound = eliminatorGroup->getFinalByStageAndNumber(finalStep,finalNumber);
			 int isSmallFinal = 0;
			 if((stageName==1)&&(finalNumber!=0)) {
				 for(int i = 0;i<eliminatorGroup->numberOfCompetitorsInRound;i++) {
					 if(eliminatorGroup->bigFinal->finishedCompetitors[i]) {
						 isSmallFinal++;
					 }
				 }
			 }
			 writeOneFinal(oneRound,isSmallFinal);
		 }

				  private: void writeFinalsProtocol(double eliminationCoefficient){
					  writeProtocolHeader(groupProtocolFile);
					  for(int groupsCounter = 0;groupsCounter < numberOfEliminatorGroups;groupsCounter++) {
						  fprintf(groupProtocolFile,"<BR>%s<B><CENTER><U>%s %s</U></CENTER></B></FONT><BR>\n",getCharArrayFromString(groupNameStyle),getCharArrayFromString(textBoxGroup->Text),groupEliminatorList[groupsCounter]->groupID);
						  fprintf(groupProtocolFile,"<table style=\"background-color: rgb(255, 255, 255);\"");
						  if(checkBoxStratch->Checked) fprintf(groupProtocolFile," width=100%%");
						  fprintf(groupProtocolFile," border=0>");
						  for(int i = 0;i<pow(eliminationCoefficient,groupEliminatorList[groupsCounter]->numberOfRounds-1);i++) {
							  fprintf(groupProtocolFile,"<tr style=\"text-align: center; color: rgb(255, 255, 255); background-color: rgb(255, 255, 255);\">");
							  for(int j = 0;j<groupEliminatorList[groupsCounter]->numberOfRounds;j++) {
								  int stepNumnum = (j>groupEliminatorList[groupsCounter]->numberOfRounds-2)?(groupEliminatorList[groupsCounter]->numberOfRounds-2):j;
								  if(fmod(pow(eliminationCoefficient,groupEliminatorList[groupsCounter]->numberOfRounds-1)-i,pow(eliminationCoefficient,stepNumnum))==0) {
									  int rowsNumber = pow(eliminationCoefficient,stepNumnum);
									  char* alignmentInTD = "center";
									  int finalStepNumber = i/pow(eliminationCoefficient,stepNumnum);
									  if(j == stepNumnum+1) {
										  if(finalStepNumber == 0) {
											  alignmentInTD = "bottom";
										  } else {
											  alignmentInTD = "top";
										  }
									  }
									  fprintf(groupProtocolFile,"<td valign=\"%s\" ROWSPAN=%d>",alignmentInTD,rowsNumber);
									  writeFinalTable(j,finalStepNumber,groupEliminatorList[groupsCounter], eliminationCoefficient);
									  fprintf(groupProtocolFile,"</td>");
								  }
							  }
							  fprintf(groupProtocolFile,"</tr>\n");
						  }
						  fprintf(groupProtocolFile,"</table>\n");
					  }
					  writeProtocolBottom(groupProtocolFile);
				   }
		   private: void fillFirstStages() {
						for(int startCounter = 0;startCounter < numberOfStartProtocolElements;startCounter++) {
							for(int groupsCounter = 0;groupsCounter < numberOfEliminatorGroups;groupsCounter++) {
								if(strcmp(startProtocolList[startCounter]->groupID,groupEliminatorList[groupsCounter]->groupID)==0) {
									groupEliminatorList[groupsCounter]->addCompetitor(
										startProtocolList[startCounter]->competitorID,
										startProtocolList[startCounter]->startDelay);
									break;
								}
							}
							
						}
					}


					private: void calculatePassedStages(int groupNumber,double eliminationCoefficient) {
								 for(int stageCounter = 0; stageCounter < groupEliminatorList[groupNumber]->numberOfRounds;stageCounter++) {
									 for(int finalsCounter = 0; finalsCounter<pow(eliminationCoefficient,groupEliminatorList[groupNumber]->numberOfRounds-stageCounter-1);finalsCounter++) {
										 FinalRound* currentRound = groupEliminatorList[groupNumber]->getFinalByStageAndNumber(stageCounter,finalsCounter);
										 if((currentRound->previousRounds[0]->filledResults && currentRound->previousRounds[1]->filledResults) || (stageCounter == 0)) {
											 FinalRound* parentRound;
											 if(stageCounter+1 < groupEliminatorList[groupNumber]->numberOfRounds) {
												 parentRound = groupEliminatorList[groupNumber]->getFinalByStageAndNumber(stageCounter+1,finalsCounter/2);
											 }
											 int numberOfRealCompetitorsInRound = 0;
											 for(int ij = 0;ij<currentRound->roundSize;ij++) {
												 if(strcmp(currentRound->numbers[ij],"")!=0) {
													 numberOfRealCompetitorsInRound++;
												 }
											 }
											 if(currentRound->roundSize>=eliminationCoefficient*numberOfRealCompetitorsInRound) {
												 currentRound->filledResults = true;
												 for(int i = 0;i<currentRound->roundSize;i++) {
													 if(strcmp(currentRound->numbers[i],"")!=0) {
														 currentRound->finishedCompetitors[i] = true;
														 for(int j = 0;j<parentRound->roundSize;j++) {
															 if(strcmp(parentRound->numbers[j],"")==0) {
																 if(stageCounter+1 < groupEliminatorList[groupNumber]->numberOfRounds) {
																	 parentRound->numbers[j] = currentRound->numbers[i];
																	 parentRound->filledNumbers = true;
																 }
																 break;
															 }
														 }
													 }
												 }
											 }
										 }
									 }
								 }
							 }


							 private: bool analyzeOneResultsItem(FinalRound* finalRoundItem, double eliminationCoefficient) {
											  for(int groupsCounter = 0;groupsCounter< numberOfEliminatorGroups;groupsCounter++) {
												  GroupEliminator* currentGroup = groupEliminatorList[groupsCounter];
												  for(int stagesCounter = 0; stagesCounter<currentGroup->numberOfRounds;stagesCounter++) {
													  for(int finalsCounter = 0; finalsCounter<((stagesCounter+1<currentGroup->numberOfRounds)?(pow(eliminationCoefficient,currentGroup->numberOfRounds-stagesCounter-1)):2);finalsCounter++) {
														  FinalRound* currentRound = currentGroup->getFinalByStageAndNumber(stagesCounter,finalsCounter);
														  bool previousFinished = (stagesCounter==0)||
															  (stagesCounter+1<currentGroup->numberOfRounds&&
															  currentRound->previousRounds[0]->filledResults && 
															  currentRound->previousRounds[1]->filledResults) ||
															  (stagesCounter+1==currentGroup->numberOfRounds&&
															  currentGroup->bigFinal->previousRounds[0]->filledResults && 
															  currentGroup->bigFinal->previousRounds[1]->filledResults);
														  bool thisFinished = currentRound->filledResults;
														  bool isThisRoundResults = currentRound->isThisResultsOfRound(finalRoundItem);
														  if(previousFinished && !thisFinished && isThisRoundResults) {
															  currentRound->setValuesInRound(finalRoundItem);
															  bool hasParent = ((stagesCounter+1)<currentGroup->numberOfRounds);
															  if(hasParent) {
																  FinalRound* parentRound = currentGroup->getFinalByStageAndNumber(stagesCounter+1, finalsCounter/2);
																  parentRound->filledNumbers = true;
																  for(int parentCounter = 0;parentCounter < currentRound->roundSize/2;parentCounter++) {
																	  for(int fillerCounter = 0;fillerCounter<parentRound->roundSize;fillerCounter++) {
																		  if(strcmp(parentRound->numbers[fillerCounter],"") == 0) {
																			  if(currentRound->finishedCompetitors[parentCounter]) {
																				  parentRound->numbers[fillerCounter] = currentRound->numbers[parentCounter];
																			  }
																			  break;
																		  }
																	  }
																  }
															  }
															  bool nextSmallFinal = ((stagesCounter+2)==currentGroup->numberOfRounds);
															  if(nextSmallFinal) {
																  FinalRound* smallFinal = currentGroup->smallFinal;
																  smallFinal->filledNumbers = true;
																  for(int parentCounter = currentRound->roundSize/2;parentCounter < currentRound->roundSize;parentCounter++) {
																	  for(int fillerCounter = 0;fillerCounter<smallFinal->roundSize;fillerCounter++) {
																		  if(strcmp(smallFinal->numbers[fillerCounter],"") == 0) {
																			  if(currentRound->finishedCompetitors[parentCounter]) {
																				  smallFinal->numbers[fillerCounter] = currentRound->numbers[parentCounter];
																			  }
																			  break;
																		  }
																	  }
																  }
															  }
															  return true;
														  }
													  }
												  }
											  }
											  return false;
									  }
							 private: void calculateFinals(double eliminationCoefficient) {
										  for(int i = 0;i<numberOfFinalRounds;i++) {
											  if(!analyzeOneResultsItem(finalRoundsList[i],eliminationCoefficient)) {
												  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Corresponding final not found for results in string ")+(i+1).ToString());
											  }
										  }
									  }
		 private: void calculateFinalsProtocol(double eliminationCoefficient){
					  fillFirstStages();
					  for(int i = 0;i<numberOfEliminatorGroups;i++) {
						  calculatePassedStages(i,eliminationCoefficient);
					  }
					  calculateFinals(eliminationCoefficient);
				  }
		 private: void checkFinalsProtocol(){
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ALWAYS_WRITE,"Method read checkFinalsProtocol() not implemented");
				  }
				  
				  
				  

private: System::Void buttonGenerateProtocol_Click(System::Object^  sender, System::EventArgs^  e) {
			 generateProtocol();
		 }
		 private: void generateProtocol() {
			 if(isInProgress) {
				 return;
			 }
			 isInProgress = true;
			 double eliminationCoefficient = 2.0;
			 try {
				 LoggerSTC::initialiseLogger(checkBoxErrAndWrnOnly->Checked ,checkBoxUseFileLogger->Checked, checkBoxUseInterfaceLogger->Checked, listBoxLogger, labelLoggerInfo);
				 if(downloadFiles()==-1) {
					 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,"Problem with downloading files");
				 }
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,"Generation of Individual Race protocol started");
				 LoggerSTC::PrintTime("Download files");
				 if(readFilesData(eliminationCoefficient)==-1) {
					 LoggerSTC::PrintTime("Read files data");
					 isInProgress = false;
					 return;
				 }
				 LoggerSTC::PrintTime("Read files data");
				 if(isEliminatorFinals()) {
					 calculateFinalsProtocol(eliminationCoefficient);
					 LoggerSTC::PrintTime("Calculate Finals protocol");
				 } else {
					 calculateProtocol();
					 LoggerSTC::PrintTime("Calculate protocol");
				 }
				 if(!isEliminatorFinals()) {
					 generateSortedProtocol();
					 LoggerSTC::PrintTime("Generate sorted protocol");
				 }
				 if(openOutputFiles() == -1) {
					 LoggerSTC::PrintTime("Open files");
					 isInProgress = false;
					 return;
				}
				 LoggerSTC::PrintTime("Open files");
				 if(isEliminatorFinals()) {
					 writeFinalsProtocol(eliminationCoefficient);
					 LoggerSTC::PrintTime("Write finals protocol");
				 } else {
					 writeGroupProtocol();
					 LoggerSTC::PrintTime("Write group protocol");
					 writeAbsoluteProtocol();
					 LoggerSTC::PrintTime("Write absolute protocol");
				 }
				 closeOutputFiles();
				 LoggerSTC::PrintTime("Close files");
				 if(isEliminatorFinals()) {
					 checkFinalsProtocol();
					 LoggerSTC::PrintTime("Check finals protocol");
				 } else {
					 checkStartProtocol();
					 LoggerSTC::PrintTime("Check protocol");
				 }
				 LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,"Generation of Individual Race protocol finished");
			 clearMemory();
			 LoggerSTC::PrintTime("Clear memory");
			 if(uploadFiles() == -1) {
				 LoggerSTC::PrintTime("Upload Files");
				 isInProgress = false;
				 return;
			 }
			 LoggerSTC::PrintTime("Upload Files");
			 } catch (Object^ e) {
				 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Some error occured in protocol generation: ") + e->ToString());
			 }
			 isInProgress = false;
	
		 }


		 private: void checkStartProtocol() {
			for(int finishCompetitorCounter = 0;finishCompetitorCounter<numberOfCompetitorElements;finishCompetitorCounter++) {
				bool elementFound = false;
				for(int competitorsCounter = 0;competitorsCounter<numberOfStartProtocolElements;competitorsCounter++) {
					if(isTheSameCompetitor(finishProtocolList[competitorsCounter],finishCompetitorList[finishCompetitorCounter])) {
						elementFound = true;
						break;
					}
				}
				if(!elementFound) {
					LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor with ID = \"") + gcnew String(finishCompetitorList[finishCompetitorCounter]->competitorID) + gcnew String("\" crossed the line according to finish protocol, but was not found in start protocol! String ") + (finishCompetitorCounter+1));
				}
			}
			for(int doubleNumbersCheckCounter = 0; doubleNumbersCheckCounter < numberOfStartProtocolElements;doubleNumbersCheckCounter++) {
				for(int secondNumberCheckCounter = 0;secondNumberCheckCounter < doubleNumbersCheckCounter;secondNumberCheckCounter++) {
					if(strcmp(startProtocolList[doubleNumbersCheckCounter]->competitorID,startProtocolList[secondNumberCheckCounter]->competitorID)==0) {
						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor with ID = \"") + gcnew String(startProtocolList[doubleNumbersCheckCounter]->competitorID) + gcnew String("\" registered 2 times in strings: ") + (secondNumberCheckCounter+1) + gcnew String(" and ") + (doubleNumbersCheckCounter+1));
					}
				}
			}

////////////////////intermediate points control
			for(int j = 0;j< numberOfPoints;j++) {
			for(int i = 0;i<numberOfRemoteElements[j];i++) {
				bool elementFound = false;
				for(int competitorsCounter = 0;competitorsCounter<numberOfStartProtocolElements;competitorsCounter++) {
					if(isTheSameCompetitor(finishProtocolList[competitorsCounter],remotePointsList[j][i])) {
						elementFound = true;
						break;
					}
				}
				if(!elementFound) {
					LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,
						gcnew String("Competitor with ID = \"") + 
						gcnew String(remotePointsList[j][i]->competitorID) + 
						gcnew String("\" crossed the line on Intermediate Point ") + 
						j.ToString() + 
						gcnew String(", but was not found in start protocol!"));
				}
			}
			}

//////////////////////////////////////////////




			for(int competitorsCounter = 0;competitorsCounter<numberOfStartProtocolElements;competitorsCounter++) {
				int numberOfLineCrosses = 0;
				for(int finishCompetitorCounter = 0;finishCompetitorCounter<numberOfCompetitorElements;finishCompetitorCounter++) {
					if(isTheSameCompetitor(finishProtocolList[competitorsCounter],finishCompetitorList[finishCompetitorCounter])) {
						numberOfLineCrosses++;
					}
				}
				int expectedNumberOfLineCrosses = startProtocolList[competitorsCounter]->numberOfLaps + (skipFirstLap()?1:0);
				if(isNumberOfTries()) {
					expectedNumberOfLineCrosses = startProtocolList[competitorsCounter]->numberOfLaps * 2;
				}
				if(numberOfLineCrosses > expectedNumberOfLineCrosses) {
					LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor with ID = \"") + gcnew String(startProtocolList[competitorsCounter]->competitorID) + gcnew String("\" crossed the line ") + numberOfLineCrosses.ToString() + gcnew String(" times but according to start protocol should cross ") + startProtocolList[competitorsCounter]->numberOfLaps.ToString() + gcnew String(" times."));
				}
			}
			if(checkBoxLapsDifference->Checked && !maskedTextBoxLapsDifference->Text->Equals(String::Empty)) {
			for(int competitorsCounter = 0;competitorsCounter <numberOfFinishProtocolElements;competitorsCounter++) {
				double averageTimePerLap = 0;
				for(int lapsCounter = 0; lapsCounter < finishProtocolList[competitorsCounter]->numberOfLapsFinished; lapsCounter++) {
					averageTimePerLap += finishProtocolList[competitorsCounter]->lapTimes[lapsCounter];
				}
				averageTimePerLap = averageTimePerLap / finishProtocolList[competitorsCounter]->numberOfLapsFinished;
				for(int lapsCounter = 0; lapsCounter < finishProtocolList[competitorsCounter]->numberOfLapsFinished; lapsCounter++) {
					if(finishProtocolList[competitorsCounter]->lapTimes[lapsCounter] > averageTimePerLap * (1 + int::Parse(maskedTextBoxLapsDifference->Text)/100.0) || finishProtocolList[competitorsCounter]->lapTimes[lapsCounter] < averageTimePerLap/(1 + int::Parse(maskedTextBoxLapsDifference->Text)/100.0)) {
						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor with ID = \"") + 
							gcnew String(finishProtocolList[competitorsCounter]->competitorID) + 
							gcnew String("\" lap ") + lapsCounter.ToString() + 
							gcnew String(" time \"") + 
							finishProtocolList[competitorsCounter]->lapTimes[lapsCounter].ToString() + 
							gcnew String("\" differs more than ") + maskedTextBoxLapsDifference->Text + gcnew String("% from average \"") +
							averageTimePerLap.ToString() + 
							gcnew String("\""));
					}
				}
			}
			}

			for(int competitorsCounter = 0;competitorsCounter<numberOfFinishProtocolElements;competitorsCounter++) {
				for(int finishCompetitorCounter = 0;finishCompetitorCounter<numberOfCompetitorElements;finishCompetitorCounter++) {
					if(isTheSameCompetitor(finishProtocolList[competitorsCounter],finishCompetitorList[finishCompetitorCounter]) && finishProtocolList[competitorsCounter]->crossLineTimes[0] > finishCompetitorList[finishCompetitorCounter]->seconds && strcmp(finishCompetitorList[finishCompetitorCounter]->action, "DSQ") != 0) {
						LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor with ID = \"") + gcnew String(finishCompetitorList[finishCompetitorCounter]->competitorID) + gcnew String("\" crossed the line at ") + finishCompetitorList[finishCompetitorCounter]->seconds.ToString() + gcnew String(" seconds before his start at ") + finishProtocolList[competitorsCounter]->crossLineTimes[0].ToString() + gcnew String(" seconds."));
					}
				}
			}







			}
	
private: void drawButton(char* buttonName, char* textBefore, char* textAfter, int numberOfGroupsToHide, int numberOfRowsToHide, FILE* outputFile) {
			  fprintf(outputFile,"<button type=\"submit\" name=\"Submit\" onClick=\"");
			  for(int groupsCounter = 0;groupsCounter < numberOfGroupsToHide; groupsCounter++) {
				  for(int cpCounter = 0; cpCounter < numberOfRowsToHide;cpCounter++) {
					  fprintf(outputFile,"%sshowhideall(%d, '%s%d%s', 1)",(groupsCounter == 0 && cpCounter == 0)?"":", ",groupsCounter,textBefore, cpCounter, textAfter);//,(groupsCounter == 0 && cpCounter == 0)?1:0);
				  }
			  }
			  fprintf(outputFile,"\" ><FONT SIZE=\"2\"><B><I>%s</I></B></FONT></button>", buttonName);
		 }

		 private: void printID(FILE* groupProtocolFile,int rowsNumber,FinishProtocolElement* competitorNumber) {
			 fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><NOBR>",rowsNumber);
			 fprintf(groupProtocolFile,"%s",competitorNumber->competitorID);
			 if(competitorNumber->stagesNumber != 1) {
				 for(int i = 1;i<competitorNumber->stagesNumber;i++) {
					 fprintf(groupProtocolFile,"<BR>%d",ProtocolStringParser::getIntByString(competitorNumber->competitorID) + i);
				 }
			 }
			 fprintf(groupProtocolFile,"</NOBR></td>\n");
		 }
		 private: void writeProtocolHeader(FILE* outputFile) {
  					  fprintf(outputFile,"<head>");
					  fprintf(outputFile,"<title>Протокол");
	
					  if(textBoxRaceName->Text!=String::Empty) {
						  fprintf(outputFile," %s", getCharArrayFromString(textBoxRaceName->Text));
					  }
					  fprintf(outputFile,"</title>");
					  fprintf(outputFile,"<meta http-equiv=\"Content-Type\" content=\"text/html; charset=Windows-1251\">\n");
					  if((checkBoxButtons->Checked && numberOfPoints>0 && !isNumberOfTries() && checkBoxShowLapTimes->Checked) || (checkBoxAllButtons->Checked && checkBoxShowLapTimes->Checked)) {
						fprintf(outputFile,"<script>\ndoShow = 0;\nfunction showhideall(table, col, isFirst) {\n	if(isFirst != 0) {\n		if(document.getElementById(table + \"_\" + col + \"_\" +  0) != null) {\n		if(document.getElementById(table + \"_\" + col + \"_\" +  0).style.display == 'none') {\n			doShow = 1;\n		} else {\n			doShow = 0;\n		}\n}\n	}\n	if(doShow != 0) {\n		show(table, col);\n	} else {\n		hide(table, col);\n	}\n}\nfunction showhide(table, col)\n{\n	if(document.getElementById(table + \"_\" + col + \"_\" +  0).style.display == 'none') {\n		show(table, col);\n	} else {\n		hide(table, col);\n	}\n}\n\nfunction show(table, col)\n{\n	for(i = 0;i<%d;i++) {\n		if(document.getElementById(table + \"_\" + col + \"_\" +  i) != null) {\n			document.getElementById(table + \"_\" + col + \"_\" +  i).style.display = 'table-cell';\n		}\n	}\n}\n\nfunction hide(table, col)\n{\n	for(i = 0; i<%d; i++) {\n		if(document.getElementById(table + \"_\" + col + \"_\" +  i) != null) {\n			document.getElementById(table + \"_\" + col + \"_\" +  i).style.display = 'none';\n		}\n	}\n}</script>\n", numberOfFinishProtocolElements+1, numberOfFinishProtocolElements+1);
					  }
					  if(commonStyleText!=String::Empty) {
						  fprintf(outputFile,"<style>\n%s\n</style>", getCharArrayFromString(commonStyleText));
					  }
					  fprintf(outputFile,"</head>\n");

//Shapka
						  if(textBoxSponsor->Text!=String::Empty) {
						  fprintf(outputFile,"<CENTER>%s</CENTER>",getCharArrayFromString(textBoxSponsor->Text));
						  }
						  if(textBoxRaceName->Text!=String::Empty) {
						  fprintf(outputFile,"%s<B><CENTER>Протокол %s</CENTER></B></FONT><BR>",
							  getCharArrayFromString(topTextStyle),
							  getCharArrayFromString(textBoxRaceName->Text));
						  }
						  if(textBoxRaceDate->Text!=String::Empty && textBoxRacePlace->Text != String::Empty) {
						  fprintf(outputFile,"%s<B><CENTER>%s, %s</CENTER></B></FONT><BR>",getCharArrayFromString(topTextStyle),getCharArrayFromString(textBoxRaceDate->Text),getCharArrayFromString(textBoxRacePlace->Text));
						  }
						  if(textBoxTrackConditions->Text!=String::Empty) {
						  fprintf(outputFile,"%s<B><CENTER>Трасса: %s</CENTER></B></FONT><BR>",getCharArrayFromString(topTextStyle),getCharArrayFromString(textBoxTrackConditions->Text));
						  }
						  if(textBoxWeather->Text!=String::Empty) {
						  fprintf(outputFile,"%s<B><CENTER>Погодные условия: %s</CENTER></B></FONT><BR>",getCharArrayFromString(topTextStyle),getCharArrayFromString(textBoxWeather->Text));
						  }

				  }
		 private: void writeProtocolBottom(FILE* outputFile) {
  							  if(textBoxOrganizator->Text!=String::Empty) {
								  fprintf(outputFile,"<FONT SIZE=\"3\" COLOR=\"\"><B><p align=\"right\">Организация соревнования: %s</p></B></FONT><BR>\n\n",getCharArrayFromString(textBoxOrganizator->Text));
							  }
							  if(textBoxMainReferee->Text!=String::Empty) {
								  fprintf(outputFile,"<FONT SIZE=\"3\" COLOR=\"\"><B><p align=\"right\">%s: %s</p></B></FONT>",getCharArrayFromString(textBoxReferee->Text),getCharArrayFromString(textBoxMainReferee->Text));
							  }
							  if(textBoxAdditionalReferee->Text!=String::Empty) {
								  fprintf(outputFile,"<FONT SIZE=\"3\" COLOR=\"\"><B><p align=\"right\">%s: %s</p></B></FONT>",getCharArrayFromString(textBoxSecretary->Text),getCharArrayFromString(textBoxAdditionalReferee->Text));
							  }
							  fprintf(outputFile,"<p align=\"left\">\n");

  							  fprintf(outputFile,"<A HREF=\"http://pulse-sports.ru/\"><IMG SRC=\"http://pulse-sports.ru/wp-content/uploads/pulse_sports_logo_small.png\" WIDTH=\"148\" HEIGHT=\"50\" BORDER=\"0\" ALT=\"\"></A><BR>\n");
							  fprintf(outputFile,"<FONT SIZE=\"2\" COLOR=\"#D7373B\"><B><I>Заставь сердце биться чаще!</I></B></FONT><BR>\n");
							  fprintf(outputFile,"<A HREF=\"http://pulse-sports.ru/forum/viewtopic.php?f=5&t=56\"><FONT SIZE=\"2\">Техническая поддержка программы судейства</FONT></A>\n");
							  fprintf(outputFile,"</p>\n");
							  fprintf(outputFile,"%s",getCharArrayFromString(textBoxBottom->Text));

				  }
	
		 private: void writeGroupProtocol() {
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function \"writeGroupProtocol()\""));
					  int allMaxNumberOfLaps = 0;
					  for(int i = 0;i<numberOfFinishProtocolElements;i++) {
						  if(checkBoxHideEmptyColumns->Checked) {
							  if(allMaxNumberOfLaps < finishProtocolList[i]->numberOfLapsFinished) {
								  allMaxNumberOfLaps = finishProtocolList[i]->numberOfLapsFinished;
							  }
						  } else {
							  if(allMaxNumberOfLaps < finishProtocolList[i]->numberOfLaps) {
								  allMaxNumberOfLaps = finishProtocolList[i]->numberOfLaps;
							  }
						  }
					  }
					  writeProtocolHeader(groupProtocolFile);

						  fprintf(groupProtocolFile,"<CENTER>");
						  if(checkBoxButtons->Checked && numberOfPoints>0 && !isNumberOfTries() && checkBoxShowLapTimes->Checked) {
							  drawButton("Скрыть/Показать<BR>Промежуточные Отсечки<BR>На Кругу","Время "," отрезка",numberOfGroups,(numberOfPoints+1)*allMaxNumberOfLaps,groupProtocolFile);
						  } 
						  if(checkBoxAllButtons->Checked && checkBoxShowLapTimes->Checked) {
							  drawButton("Скрыть/Показать<BR>Дополнительную Статистику<BR>По Кругам", "Дополнительная ", " инфа", numberOfGroups, allMaxNumberOfLaps,groupProtocolFile);
						  }
						  fprintf(groupProtocolFile,"</CENTER>");

//End Shapka
					  for(int groupsCounter = 0;groupsCounter<numberOfGroups;groupsCounter++) {
						  FinishProtocolElement* leaderOfGroup;
						  bool groupLeaderFound;
						  groupLeaderFound = false;
						  int placeCounter;
						  placeCounter = 0;
						  int numberOfLapsForGroup = 0;
						  if(checkBoxHideEmptyColumns->Checked) {
							  for(int i = 0;i<numberOfFinishProtocolElements;i++) {
								  if(strcmp(finishProtocolList[i]->groupID,groupStartList[groupsCounter]->groupID)==0) {
									  if(numberOfLapsForGroup < finishProtocolList[i]->numberOfLapsFinished) {
										  numberOfLapsForGroup = finishProtocolList[i]->numberOfLapsFinished;
									  }
								  }
							  }
						  } else {
							  for(int i = 0;i<numberOfStartProtocolElements;i++) {
								  if(strcmp(startProtocolList[i]->groupID,groupStartList[groupsCounter]->groupID)==0) {
									  numberOfLapsForGroup = startProtocolList[i]->numberOfLaps;
									  break;
								  }
							  }
						  }
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Number of Laps for group \"" )+ gcnew String(groupStartList[groupsCounter]->groupID) + gcnew String("\" equals ") + numberOfLapsForGroup.ToString());
						  rowsNumber = 1 + ((numberOfLapsForGroup>1 || !checkBoxShowFinishTime->Checked)?
							  ((numberOfPoints>0 && !isNumberOfTries() && checkBoxShowLapTimes->Checked)?1:0) 
							  + ((checkBoxAllButtons->Checked && checkBoxShowLapTimes->Checked)?1:0)
							  :0);
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Number of Laps for group \"" )+ gcnew String(groupStartList[groupsCounter]->groupID) + gcnew String("\" equals ") + rowsNumber.ToString());
						  fprintf(groupProtocolFile,"<BR>%s<B><CENTER><U>%s %s</U></CENTER></B></FONT><BR><table style=\"%s\"",getCharArrayFromString(groupNameStyle),getCharArrayFromString(textBoxGroup->Text),groupStartList[groupsCounter]->groupID, getCharArrayFromString(tableStyle));
						  if(checkBoxStratch->Checked) fprintf(groupProtocolFile," width=100%%");
						  fprintf(groupProtocolFile," border=0>");
						  fprintf(groupProtocolFile,"<tr style=\"%s\">", getCharArrayFromString(topLineStyle));
						  if(checkBoxShowPlace->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxPlace->Text));
						  if(checkBoxShowID->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxID->Text));
						  if(checkBoxShowName->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxName->Text));
						  if(checkBoxShowAge->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxAge->Text));
						  if(checkBoxShowTeam->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B><NOBR>%s</NOBR></B></td>\n",rowsNumber,getCharArrayFromString(textBoxTeam->Text));
						  if(checkBoxShowCity->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxCity->Text));
						  if(checkBoxShowLapTimes->Checked) {
						  if(numberOfLapsForGroup > 1 || !checkBoxShowFinishTime->Checked) {
						  for(int j = 0;j<numberOfLapsForGroup;j++) {
							  fprintf(groupProtocolFile,"<td ALIGN=center COLSPAN=%d>",columnsNumber);
							  fprintf(groupProtocolFile,"<B>Время %d %s",j+1, getCharArrayFromString(textBoxLapName->Text));

							  if(checkBoxLapFinnish->Checked) fprintf(groupProtocolFile,"<BR>%s%s</FONT>", getCharArrayFromString(additionalTextTopStyle), getCharArrayFromString(textBoxLapAdditionalInfo->Text));
							  fprintf(groupProtocolFile,"</B></td>\n");
							  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Created table for group \"") + gcnew String(groupStartList[groupsCounter]->groupID) + gcnew String("\" for lap number ") + j.ToString());
						  }
						  }
						  }
						  if(checkBoxShowFinishTime->Checked) { 
							  fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>",rowsNumber);
  							  fprintf(groupProtocolFile,"<B><NOBR>Результат<BR>");
							  if(checkBoxTimeDifference->Checked) fprintf(groupProtocolFile,"%s(Отставание от лидера)</FONT></NOBR><BR>", getCharArrayFromString(additionalTextTopStyle));
							  if(checkBoxNumberOfFinishedLaps->Checked) fprintf(groupProtocolFile,"<FONT SIZE=\"3\">(Кругов)</FONT></NOBR>");
							  fprintf(groupProtocolFile,"</B></td>\n");
						  }
						  if(checkBoxAdditionalInfo->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxAdditonalInfo->Text));
						  if(checkBoxTimeShift->Checked) 
							  {
							  fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxTimeShift->Text));
						  }


						  if(checkBoxShowLapTimes->Checked) {
							  if(numberOfLapsForGroup > 1 || !checkBoxShowFinishTime->Checked) {
						  if(checkBoxAllButtons->Checked) {
							  fprintf(groupProtocolFile,"</tr>\n<tr style=\"%s\">\n", getCharArrayFromString(topLineStyle));
							  for(int j = 0;j<numberOfLapsForGroup;j++) {
								  fprintf(groupProtocolFile,"<td COLSPAN=%d ROWSPAN=1 id=\"%d_Дополнительная %d инфа_0\" ALIGN=center><FONT SIZE=\"1\"><B>Отставание(место)", columnsNumber, groupsCounter ,j);
								  if(checkBoxLapFinnish->Checked) {
									  fprintf(groupProtocolFile,"<BR>%sФиниш %s: отставание(место)",getCharArrayFromString(additionalInfoTopStyle), getCharArrayFromString(textBoxLapName->Text));
								  }
								  fprintf(groupProtocolFile,"</FONT></B></FONT></td>\n");
							  }
						  }
						  if(numberOfPoints>0 && !isNumberOfTries()) {
							  fprintf(groupProtocolFile,"</tr>\n<tr style=\"%s\">\n", getCharArrayFromString(topLineStyle));
							  for(int j = 0;j<numberOfLapsForGroup;j++) {
								  for(int cpCounter = 0; cpCounter < numberOfPoints+1; cpCounter++) {
									  fprintf(groupProtocolFile,"<td ROWSPAN=1 id=\"%d_Время %d отрезка_0\" ALIGN=center><FONT SIZE=\"1\"><B><NOBR>(%d отрезок)</NOBR></B></FONT>", groupsCounter ,cpCounter+j*(numberOfPoints+1), cpCounter+1);
									  fprintf(groupProtocolFile,"</td>\n");
								  }
							  }
						  }
							  }
						  }
  						  fprintf(groupProtocolFile,"</tr>\n");



						  for(int competitorsCounter = 0; competitorsCounter< numberOfFinishProtocolElements;competitorsCounter++) {
							  if(!checkBoxDisableDNF->Checked && (finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] == 0 || finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] == double::MaxValue)) {
								  finishProtocolListSorted[competitorsCounter]->finished = false;
							  }
							  if(strcmp(finishProtocolListSorted[competitorsCounter]->groupID,groupStartList[groupsCounter]->groupID)==0 && (finishProtocolListSorted[competitorsCounter]->finished || checkBoxPrintDNF->Checked) && (finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished!=0 || checkBoxPrintDNS->Checked) && (!finishProtocolListSorted[competitorsCounter]->disqualified || checkBoxPrintDSQ->Checked)) {
								  placeCounter++;
								  if(fmod(placeCounter,2.0) == 0.0) {
									 fprintf(groupProtocolFile,"<tr style=\"%s\">",getCharArrayFromString(oddLineStyle));
								  } else {
									 fprintf(groupProtocolFile,"<tr style=\"%s\">",getCharArrayFromString(evenLineStyle));
								  }
								  if(checkBoxShowPlace->Checked) {
								  if(finishProtocolListSorted[competitorsCounter]->disqualified) {
									  fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>DSQ</td>\n",rowsNumber);
								  } else if(!finishProtocolListSorted[competitorsCounter]->finished) {
									  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished!=0 && finishProtocolListSorted[competitorsCounter]->crossLineTimes[0]!=0 && finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] != double::MaxValue) {
										  fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>DNF</td>\n",rowsNumber);
									  } else {
										  if(skipFirstLap() && finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] != double::MaxValue) {
											fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>DNF</td>\n",rowsNumber);
										  } else {
											fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>DNS</td>\n",rowsNumber);
										  }
									  }
								  } else {
									  fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>%d</td>\n",rowsNumber,placeCounter);
									  if(generateTextFinishProtocol()) {
										  fprintf(groupProtocolFileText,"%s\n", 
											  getCharArrayFromString(finishProtocolListSorted[competitorsCounter]->ToString("#", placeCounter)));
									  }
								  }
								  }
						  
								  if(checkBoxShowID->Checked) printID(groupProtocolFile,rowsNumber,finishProtocolListSorted[competitorsCounter]);
								  if(checkBoxShowName->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber, finishProtocolListSorted[competitorsCounter]->competitorName);
								  if(checkBoxShowAge->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber, finishProtocolListSorted[competitorsCounter]->competitorYearOfBirth);
								  if(checkBoxShowTeam->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber, finishProtocolListSorted[competitorsCounter]->competitorTeam);
								  if(checkBoxShowCity->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber, finishProtocolListSorted[competitorsCounter]->competitorCity);
								  if(checkBoxShowLapTimes->Checked) {
									  if(numberOfLapsForGroup > 1 || !checkBoxShowFinishTime->Checked) {
							  for(int lapsCompetitorCounter = 0;lapsCompetitorCounter <numberOfLapsForGroup;lapsCompetitorCounter++) {
								  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished>lapsCompetitorCounter) {
									  fprintf(groupProtocolFile,"<td ALIGN=center COLSPAN=%d>", columnsNumber);
										  writeTimeByDouble(groupProtocolFile, finishProtocolListSorted[competitorsCounter]->lapTimes[lapsCompetitorCounter]);
										  fprintf(groupProtocolFile,"<NOBR>%s</NOBR>",finishProtocolListSorted[competitorsCounter]->lapPenaltyComment[lapsCompetitorCounter]);
										  if(finishProtocolListSorted[competitorsCounter]->stagesNumber != 1 && finishProtocolListSorted[competitorsCounter]->lapFinishNumbers[lapsCompetitorCounter] != -1) {
											  fprintf(groupProtocolFile,"(%d)",finishProtocolListSorted[competitorsCounter]->lapFinishNumbers[lapsCompetitorCounter]);
										  }
											if(checkBoxLapFinnish->Checked) {
											  fprintf(groupProtocolFile,"<BR>%s(",getCharArrayFromString(additionalTextStyle));
											  writeTimeByDouble(groupProtocolFile, finishProtocolListSorted[competitorsCounter]->finishLapTimes[lapsCompetitorCounter]);
											  fprintf(groupProtocolFile,")</FONT>");
											  }
									  fprintf(groupProtocolFile,"</td>\n");
								  } else {
									  fprintf(groupProtocolFile,"<td ALIGN=center COLSPAN=%d></td>\n", columnsNumber);
								  }
								  							  
							  }

//							  }
							  }
								  }
							if(checkBoxShowFinishTime->Checked) {
								fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>", rowsNumber);
								if(finishProtocolListSorted[competitorsCounter]->finished && !finishProtocolListSorted[competitorsCounter]->disqualified) {
  									if(!groupLeaderFound) {
										leaderOfGroup = finishProtocolListSorted[competitorsCounter];
										groupLeaderFound = true;
									}


// current result and time difference calculation

								  bool timeDifferenceFound = true;									
								  double lastCompetitorTime = isNumberOfTries()?finishProtocolListSorted[competitorsCounter]->getTotalTime(false):finishProtocolListSorted[competitorsCounter]->finishLapTimes[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished-1];
								  double lastLeaderTime = leaderOfGroup->finishLapTimes[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished-1];
								  int lastCPCompetitor = -1;
								  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished < finishProtocolListSorted[competitorsCounter]->numberOfLaps) {
									  for(int leaderCPCpounter = 0; leaderCPCpounter<numberOfPoints;leaderCPCpounter++) {
										  if(finishProtocolListSorted[competitorsCounter]->controlPoints[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished]->segmentFinishes[leaderCPCpounter]!=-1) {
											  lastCPCompetitor = leaderCPCpounter;
										  }
									  }
								  }
								  if(lastCPCompetitor != -1) {
									  lastCompetitorTime = lastCompetitorTime + 
										  finishProtocolListSorted[competitorsCounter]->controlPoints[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished]->segmentFinishes[lastCPCompetitor];
									  if(leaderOfGroup->controlPoints[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished]->segmentFinishes[lastCPCompetitor] != -1) {
										  timeDifferenceFound = true;
										  lastLeaderTime = lastLeaderTime + 
											  leaderOfGroup->controlPoints[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished]->segmentFinishes[lastCPCompetitor];
									  } else {
										  timeDifferenceFound = false;
									  }
								  }
								  if(lastCompetitorTime > 0.0) {
//									  fprintf(groupProtocolFile,"Время в секундах:%fсекунд<BR>", lastCompetitorTime);
									  writeTimeByDouble(groupProtocolFile,lastCompetitorTime);
									  if(groupLeaderFound&&checkBoxTimeDifference->Checked) {
										  fprintf(groupProtocolFile,"<BR>%s(",getCharArrayFromString(additionalTextStyle));
										  if(isNumberOfTries()) {
											  if(finishProtocolListSorted[competitorsCounter]->getTimeDifference(leaderOfGroup, false) > 0) fprintf(groupProtocolFile,"+");
											  writeTimeByDouble(groupProtocolFile, finishProtocolListSorted[competitorsCounter]->getTimeDifference(leaderOfGroup, false));
										  } else {
											  if(timeDifferenceFound) {
												  if(lastCompetitorTime - lastLeaderTime > 0) fprintf(groupProtocolFile,"+");
												  writeTimeByDouble(groupProtocolFile, lastCompetitorTime - lastLeaderTime);
											  } else {
												  fprintf(groupProtocolFile,"Неизвестно");
											  }
										  }
										  fprintf(groupProtocolFile,")</FONT>");
										}
									  
									  if(checkBoxNumberOfFinishedLaps->Checked) {
										  fprintf(groupProtocolFile,"<BR><FONT SIZE=\"3\">(%d)</FONT>", isNumberOfTries()?finishProtocolListSorted[competitorsCounter]->getNumberOfSuccessfullyFinishedTries(false):finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished);
									  }
								  }
								  fprintf(groupProtocolFile,"</td>\n");
//FINISH current result and time difference calculation 

							  } else {
//									  fprintf(groupProtocolFile,"--:--:--.-");
									  fprintf(groupProtocolFile,"</td>\n");
							  }
							  }
								  if(checkBoxAdditionalInfo->Checked) fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber,finishProtocolListSorted[competitorsCounter]->competitorAdditionalInfo);
								  if(checkBoxTimeShift->Checked){
									  fprintf(groupProtocolFile,"<td ALIGN=center ROWSPAN=%d>",rowsNumber);
									  if(skipFirstLap()) {
										  if(finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] == double::MaxValue) {
											  fprintf(groupProtocolFile, "NOT STARTED");
										  } else {
											writeTimeByDouble(groupProtocolFile,finishProtocolListSorted[competitorsCounter]->crossLineTimes[0], true);
										  }
									  } else {
										writeTimeByDouble(groupProtocolFile, finishProtocolListSorted[competitorsCounter]->startDelay);
									  }
									  fprintf(groupProtocolFile,"</td>\n");
								  }

								  if(checkBoxShowLapTimes->Checked) {
									  if(numberOfLapsForGroup > 1 || !checkBoxShowFinishTime->Checked) {
										  if(checkBoxAllButtons->Checked) {
										  if(fmod(placeCounter,2.0) == 0.0) {
											  fprintf(groupProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(oddLineStyle));
										  } else {
											 fprintf(groupProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(evenLineStyle));
										  }
									  for(int j = 0;j<numberOfLapsForGroup;j++) {
										  double bestFinish = finishProtocolListSorted[competitorsCounter]->finishLapTimes[j];
										  double thisFinish = bestFinish;
										  int placeFinish = 1;
										  double bestLap = finishProtocolListSorted[competitorsCounter]->lapTimes[j];
										  double thisLap = bestLap;
										  int placeLap = 1;

										  for(int lapLeadCounter = 0; lapLeadCounter < numberOfFinishProtocolElements; lapLeadCounter++){
											  if(strcmp(groupStartList[groupsCounter]->groupID,finishProtocolListSorted[lapLeadCounter]->groupID)==0 && finishProtocolListSorted[lapLeadCounter]->numberOfLapsFinished > j) {
												  if(finishProtocolListSorted[lapLeadCounter]->lapTimes[j] < thisLap) {
													  placeLap++;
													  if(finishProtocolListSorted[lapLeadCounter]->lapTimes[j] < bestLap) {
														  bestLap = finishProtocolListSorted[lapLeadCounter]->lapTimes[j];
													  }
												  }
												  if(finishProtocolListSorted[lapLeadCounter]->finishLapTimes[j] < thisFinish) {
													  placeFinish++;
													  if(finishProtocolListSorted[lapLeadCounter]->finishLapTimes[j] < bestFinish) {
														  bestFinish = finishProtocolListSorted[lapLeadCounter]->finishLapTimes[j];
													  }
												  }
											  }
										  }
										  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished > j) {
											  fprintf(groupProtocolFile,"<td COLSPAN=%d ROWSPAN=1 id=\"%d_Дополнительная %d инфа_%d\" ALIGN=center><FONT SIZE=\"1\">%s", columnsNumber, groupsCounter ,j, placeCounter+1,(placeLap==1)?"<B>":"");
											  writeTimeByDouble(groupProtocolFile,thisLap-bestLap);
											  fprintf(groupProtocolFile,"&nbsp(%d)%s",placeLap,(placeLap==1)?"</B>":"");
											  if(checkBoxLapFinnish->Checked) {
												  fprintf(groupProtocolFile,"<BR>%s%s",(placeFinish==1)?"<B>":"",getCharArrayFromString(additionalInfoStyle));
												  writeTimeByDouble(groupProtocolFile,thisFinish-bestFinish);
												  fprintf(groupProtocolFile,"&nbsp(%d)</FONT>%s",placeFinish, (placeFinish==1)?"<B>":"");
											  }
											  fprintf(groupProtocolFile,"</FONT></td>\n");
										  } else {
											  fprintf(groupProtocolFile,"<td COLSPAN=%d ROWSPAN=1 id=\"%d_Дополнительная %d инфа_%d\" ALIGN=center></td>", columnsNumber, groupsCounter ,j, placeCounter+1);
										  }
									  }
								  }





								  if(numberOfPoints>0 && !isNumberOfTries()) {
									  if(fmod(placeCounter,2.0) == 0.0) {
										  fprintf(groupProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(oddLineStyle));
									  } else {
										 fprintf(groupProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(evenLineStyle));
									  }
									  for(int lapsCompetitorCounter = 0;lapsCompetitorCounter <numberOfLapsForGroup;lapsCompetitorCounter++) {
										  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished+1>lapsCompetitorCounter && lapsCompetitorCounter < finishProtocolListSorted[competitorsCounter]->numberOfLaps) {
											  for(int cpCounter = 0; cpCounter < numberOfPoints; cpCounter++) {
													  fprintf(groupProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\">(", groupsCounter, (lapsCompetitorCounter*(numberOfPoints+1))+cpCounter, competitorsCounter + 1);
													  if(finishProtocolListSorted[competitorsCounter]->
														  controlPoints[lapsCompetitorCounter]->
														  segmentTimes[cpCounter] != -1) {
														  if(finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentTimes[cpCounter] != -2) {
															writeTimeByDouble(groupProtocolFile, finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentTimes[cpCounter]);
														  } else {
															fprintf(groupProtocolFile,"<FONT COLOR=\"#FF0000\">Неизвестно</FONT>");
														  }
													  } else {
														fprintf(groupProtocolFile,"<FONT COLOR=\"#FF0000\">Неявка</FONT>");
														LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Control point \"") + (cpCounter+1).ToString() + gcnew String("\" on lap \"") + (lapsCompetitorCounter+1).ToString() + gcnew String("\"of competitor with number \"") + gcnew String(  finishProtocolListSorted[competitorsCounter]->competitorID) + gcnew String("\" NOT FOUND!!!"));
													  }
											  fprintf(groupProtocolFile,")</FONT></td>\n");
											  }
											  if(lapsCompetitorCounter >= finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished){
												  fprintf(groupProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\">(<FONT COLOR=\"#FF0000\">Неявка</FONT>)</td>\n", groupsCounter,((lapsCompetitorCounter+1)*(numberOfPoints+1))-1, competitorsCounter + 1);
											  } else {
												  if(finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentCrosses[numberOfPoints-1] == -1) {
													  fprintf(groupProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\"><FONT SIZE=\"1\">(<FONT COLOR=\"#FF0000\">Неизвестно</FONT>)</FONT></td>\n", groupsCounter, ((lapsCompetitorCounter+1)*(numberOfPoints+1))-1, competitorsCounter + 1);
												  } else {
													  fprintf(groupProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\">(", groupsCounter, ((lapsCompetitorCounter+1)*(numberOfPoints+1))-1, competitorsCounter + 1);
													  writeTimeByDouble(groupProtocolFile, finishProtocolListSorted[competitorsCounter]->crossLineTimes[lapsCompetitorCounter+1] - finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentCrosses[numberOfPoints-1]);
													  fprintf(groupProtocolFile,")</FONT></td>\n");
												  }
											  }
										  } else {
											  for(int cpCounter = 0; cpCounter < numberOfPoints+1; cpCounter++) {
												  fprintf(groupProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center></td>\n", groupsCounter, (lapsCompetitorCounter*(numberOfPoints+1))+cpCounter, competitorsCounter + 1);
											  }
										  }
									  }
								  }
								  }
								  }


							fprintf(groupProtocolFile,"</tr>\n");
							  }

						  }
						  fprintf(groupProtocolFile,"</table>");
					  }
//BOTTOM
							  writeProtocolBottom(groupProtocolFile);


						  //END BOTTOM
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function \"writeGroupProtocol()\""));
				  }
		 private: void writeAbsoluteProtocol() {
					  int groupsCounter = 0;
						  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function \"writeAbsoluteProtocol()\""));
						  writeProtocolHeader(absoluteProtocolFile);
						  int maxNumberOfLaps = 0;
						  if(checkBoxHideEmptyColumns->Checked) {
							  for(int i = 0;i<numberOfFinishProtocolElements;i++) {
								  if(maxNumberOfLaps < finishProtocolList[i]->numberOfLapsFinished) {
									  maxNumberOfLaps = finishProtocolList[i]->numberOfLapsFinished;
								  }
							  }
						  } else {
							  for(int i = 0;i<numberOfFinishProtocolElements;i++) {
								  if(maxNumberOfLaps < finishProtocolList[i]->numberOfLaps) {
									  maxNumberOfLaps = finishProtocolList[i]->numberOfLaps;
								  }
							  }
						  }
						  rowsNumber = 1 + ((maxNumberOfLaps>1 || !checkBoxShowFinishTime->Checked)?
							  ((numberOfPoints>0 && !isNumberOfTries() && checkBoxShowLapTimes->Checked)?1:0) 
							  + ((checkBoxAllButtons->Checked && checkBoxShowLapTimes->Checked)?1:0)
							  :0);

						  fprintf(absoluteProtocolFile,"<CENTER>");
						  if(checkBoxButtons->Checked && numberOfPoints>0 && checkBoxShowLapTimes->Checked && !isNumberOfTries()) {
							  drawButton("Скрыть/Посказать<BR>Промежуточные Отсечки<BR>На Кругу", "Время ", " отрезка", 1, (numberOfPoints+1)*maxNumberOfLaps, absoluteProtocolFile);
						  }
						  if(checkBoxAllButtons->Checked && checkBoxShowLapTimes->Checked) {
							  drawButton("Скрыть/Показать<BR>Дополнительную Статистику<BR>По Кругам", "Дополнительная ", " инфа", 1, maxNumberOfLaps,absoluteProtocolFile);
						  }
						  fprintf(absoluteProtocolFile,"</CENTER>");

							  
//End Shapka
						  fprintf(absoluteProtocolFile,"<BR>%s<B><CENTER><U>Абсолютный протокол</U></CENTER></B></FONT><BR><table style=\"%s\"",getCharArrayFromString(groupNameStyle),getCharArrayFromString(tableStyle));
						  if(checkBoxStratch->Checked) fprintf(absoluteProtocolFile," width=100%%");
						  fprintf(absoluteProtocolFile," border=0>");
						  fprintf(absoluteProtocolFile,"<tr style=\"%s\">", getCharArrayFromString(topLineStyle));

						  if(checkBoxShowPlace->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,  getCharArrayFromString(textBoxPlace->Text));
						  if(checkBoxShowID->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxID->Text));
						  if(checkBoxShowName->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxName->Text));
						  if(checkBoxShowAge->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxAge->Text));
						  if(checkBoxShowGroup->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxGroup->Text));
						  if(checkBoxShowTeam->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxTeam->Text));
						  if(checkBoxShowCity->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxCity->Text));

						  if(checkBoxShowLapTimes->Checked) {
							  if(maxNumberOfLaps > 1 || !checkBoxShowFinishTime->Checked) {
						  for(int j = 0;j<maxNumberOfLaps;j++) {

							  fprintf(absoluteProtocolFile,"<td ALIGN=center COLSPAN=%d>", columnsNumber);
							  fprintf(absoluteProtocolFile,"<B>Время %d %s",j+1, getCharArrayFromString(textBoxLapName->Text));
							  if(checkBoxLapFinnish->Checked) fprintf(absoluteProtocolFile,"<BR>%s%s</FONT>", getCharArrayFromString(additionalTextTopStyle), getCharArrayFromString(textBoxLapAdditionalInfo->Text));
							  fprintf(absoluteProtocolFile,"</B></td>\n");
						  }
							  }
						  }
						  if(checkBoxShowFinishTime->Checked) {
							  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>",rowsNumber);
  							  fprintf(absoluteProtocolFile,"<B>Результат<BR>");

							  if(checkBoxTimeDifference->Checked) fprintf(absoluteProtocolFile,"%s(Отставание от лидера)</FONT></B>", getCharArrayFromString(additionalTextTopStyle));
							  if(checkBoxNumberOfFinishedLaps->Checked) fprintf(absoluteProtocolFile,"<FONT SIZE=\"3\">(Кругов)</FONT></NOBR>");
							  fprintf(absoluteProtocolFile,"</B></td>\n");
						  }
						  if(checkBoxAdditionalInfo->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxAdditonalInfo->Text));
						  if(checkBoxTimeShift->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><B>%s</B></td>\n",rowsNumber,getCharArrayFromString(textBoxTimeShift->Text));

						  if(checkBoxShowLapTimes->Checked) {
							  if(maxNumberOfLaps > 1 || !checkBoxShowFinishTime->Checked) {
						  if(checkBoxAllButtons->Checked) {
							  fprintf(absoluteProtocolFile,"</tr>\n<tr style=\"%s\">\n", getCharArrayFromString(topLineStyle));
							  for(int j = 0;j<maxNumberOfLaps;j++) {
									  fprintf(absoluteProtocolFile,"<td COLSPAN=%d id=\"%d_Дополнительная %d инфа_0\" ALIGN=center><FONT SIZE=\"1\"><B>Отставание(место)", columnsNumber, groupsCounter ,j);
									  if(checkBoxLapFinnish->Checked) {
										  fprintf(absoluteProtocolFile,"<BR>%sФиниш %s: отставание(место)", getCharArrayFromString(additionalInfoTopStyle), getCharArrayFromString(textBoxLapName->Text));
									  }
									  fprintf(absoluteProtocolFile,"</FONT></B></FONT></td>\n");
							  }
						  }
						  if(numberOfPoints>0 && !isNumberOfTries()) {
							  fprintf(absoluteProtocolFile,"</tr>\n<tr style=\"%s\">\n", getCharArrayFromString(topLineStyle));
							  for(int j = 0;j<maxNumberOfLaps;j++) {
								  for(int cpCounter = 0; cpCounter < numberOfPoints+1; cpCounter++) {
									  fprintf(absoluteProtocolFile,"<td id=\"%d_Время %d отрезка_0\" ALIGN=center><FONT SIZE=\"1\"><B><NOBR>(%d отрезок)</NOBR></B></FONT>", groupsCounter ,cpCounter+j*(numberOfPoints+1), cpCounter+1);
									  fprintf(absoluteProtocolFile,"</td>\n");
								  }
							  }
						  }
							  }
						  }
  						  fprintf(absoluteProtocolFile,"</tr>\n");

						  double absoluteLeader;
						  bool absoluteLeaderFound;
						  FinishProtocolElement* absoluteLeaderInfo;
						  absoluteLeader = 0;
						  absoluteLeaderFound = false;
						  for(int competitorsCounter = 0; competitorsCounter< numberOfFinishProtocolElements;competitorsCounter++) {
  							  if(!checkBoxDisableDNF->Checked && (finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] == 0 || finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] == double::MaxValue)) {
								  finishProtocolListSorted[competitorsCounter]->finished = false;
							  }

							  if((finishProtocolListSorted[competitorsCounter]->finished || checkBoxPrintDNF->Checked) && (finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished!=0 || checkBoxPrintDNS->Checked) && (!finishProtocolListSorted[competitorsCounter]->disqualified || checkBoxPrintDSQ->Checked)) {
								  if(fmod(competitorsCounter,2.0) != 0.0) {
									 fprintf(absoluteProtocolFile,"<tr style=\"%s\">",getCharArrayFromString(oddLineStyle));
								  } else {
									 fprintf(absoluteProtocolFile,"<tr style=\"%s\">",getCharArrayFromString(evenLineStyle));
								  }
								  if(checkBoxShowPlace->Checked) {
								  if(finishProtocolListSorted[competitorsCounter]->disqualified) {
									  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>DSQ</td>\n",rowsNumber, groupsCounter, getCharArrayFromString(textBoxPlace->Text), competitorsCounter + 1);
								  } else if(!finishProtocolListSorted[competitorsCounter]->finished) {
									  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished!=0 && finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] != 0 || finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] != double::MaxValue) {
										  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>DNF</td>\n",rowsNumber);
									  } else {
										  if(skipFirstLap() && finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] != double::MaxValue) {
											fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>DNF</td>\n",rowsNumber);
										  } else {
											fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>DNS</td>\n",rowsNumber);
										  }
									  }
								  } else {
									  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>%d</td>\n",rowsNumber,competitorsCounter + 1);
								  }
								  }
	
								  if(checkBoxShowID->Checked) printID(absoluteProtocolFile,rowsNumber,finishProtocolListSorted[competitorsCounter]);
								  if(checkBoxShowName->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber,finishProtocolListSorted[competitorsCounter]->competitorName);
								  if(checkBoxShowAge->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber,finishProtocolListSorted[competitorsCounter]->competitorYearOfBirth);
								  if(checkBoxShowGroup->Checked) {
									  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><NOBR>%s",rowsNumber,finishProtocolListSorted[competitorsCounter]->groupID);
									  int foundGroup = -1;
									  for(int groupsPlaceCounter = 0; groupsPlaceCounter < numberOfGroups;groupsPlaceCounter++) {
										  if(strcmp(groupStartList[groupsPlaceCounter]->groupID, finishProtocolListSorted[competitorsCounter]->groupID) == 0) {
											  foundGroup = groupsPlaceCounter;
											  break;
										  }
									  }
									  if(foundGroup != -1 && !finishProtocolListSorted[competitorsCounter]->disqualified && finishProtocolListSorted[competitorsCounter]->finished) {
										  fprintf(absoluteProtocolFile,"(%d)",groupStartList[foundGroup]->place);
										  groupStartList[foundGroup]->place++;
									  }
									  fprintf(absoluteProtocolFile,"</NOBR></td>\n");
								  }
								  if(checkBoxShowTeam->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d><NOBR>%s</NOBR></td>\n",rowsNumber, finishProtocolListSorted[competitorsCounter]->competitorTeam);
								  if(checkBoxShowCity->Checked) fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber, finishProtocolListSorted[competitorsCounter]->competitorCity);

								  if(checkBoxShowLapTimes->Checked) {
									  if(maxNumberOfLaps > 1 || !checkBoxShowFinishTime->Checked) {
							  for(int lapsCompetitorCounter = 0;lapsCompetitorCounter <maxNumberOfLaps;lapsCompetitorCounter++) {
								  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished>lapsCompetitorCounter) {
									  fprintf(absoluteProtocolFile,"<td ALIGN=center COLSPAN=%d>", columnsNumber);
									  writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->lapTimes[lapsCompetitorCounter]);
									  fprintf(absoluteProtocolFile,"<NOBR>%s</NOBR>",finishProtocolListSorted[competitorsCounter]->lapPenaltyComment[lapsCompetitorCounter]);
										  if(finishProtocolListSorted[competitorsCounter]->stagesNumber != 1 && finishProtocolListSorted[competitorsCounter]->lapFinishNumbers[lapsCompetitorCounter] != -1) {
											  fprintf(absoluteProtocolFile,"(%d)",finishProtocolListSorted[competitorsCounter]->lapFinishNumbers[lapsCompetitorCounter]);
										  }
									  if(checkBoxLapFinnish->Checked) {
									  fprintf(absoluteProtocolFile,"<BR>%s(",getCharArrayFromString(additionalTextStyle));
									  writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->finishLapTimes[lapsCompetitorCounter]);
									  fprintf(absoluteProtocolFile,")</FONT>");
									  }
									  fprintf(absoluteProtocolFile,"</td>\n");
								  } else {
									  fprintf(absoluteProtocolFile,"<td ALIGN=center COLSPAN=%d></td>\n",columnsNumber);
								  }
							  }
									  }
								  }
								  if(checkBoxShowFinishTime->Checked) {
							  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>",rowsNumber);
							  if(finishProtocolListSorted[competitorsCounter]->finished && !finishProtocolListSorted[competitorsCounter]->disqualified) {
								  if(!absoluteLeaderFound) {
									  absoluteLeaderFound = true;
									  absoluteLeader = finishProtocolListSorted[competitorsCounter]->finishLapTimes[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished-1];
									  absoluteLeaderInfo = finishProtocolListSorted[competitorsCounter];
								  }
								writeTimeByDouble(absoluteProtocolFile,isNumberOfTries()?finishProtocolListSorted[competitorsCounter]->getTotalTime(false):finishProtocolListSorted[competitorsCounter]->finishLapTimes[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished-1]);
								if(checkBoxTimeDifference->Checked) {
									fprintf(absoluteProtocolFile,"<BR>%s(",getCharArrayFromString(additionalTextStyle));
								    if(isNumberOfTries()) {
										if(finishProtocolListSorted[competitorsCounter]->getTimeDifference(absoluteLeaderInfo, false) > 0) fprintf(absoluteProtocolFile,"+");
										writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->getTimeDifference(absoluteLeaderInfo, false));
									} else {
										if(absoluteLeaderFound) {
											if(finishProtocolListSorted[competitorsCounter]->finishLapTimes[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished-1]-absoluteLeader > 0) fprintf(absoluteProtocolFile,"+");
											writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->finishLapTimes[finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished-1]-absoluteLeader);
										}
									}
									  fprintf(absoluteProtocolFile,")</FONT>");
								}
								  if(checkBoxNumberOfFinishedLaps->Checked) {
									  fprintf(absoluteProtocolFile,"<BR><FONT SIZE=\"3\">(%d)</FONT>", isNumberOfTries()?finishProtocolListSorted[competitorsCounter]->getNumberOfSuccessfullyFinishedTries(false):finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished);
								  }
							  fprintf(absoluteProtocolFile,"</td>\n");

							  } else {
									  fprintf(absoluteProtocolFile,"</td>\n");
							  }
								  }
								  if(checkBoxAdditionalInfo->Checked)  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>%s</td>\n",rowsNumber,finishProtocolListSorted[competitorsCounter]->competitorAdditionalInfo);
								  if(checkBoxTimeShift->Checked){
									  fprintf(absoluteProtocolFile,"<td ALIGN=center ROWSPAN=%d>",rowsNumber);
									  if(skipFirstLap()) {
										  if(finishProtocolListSorted[competitorsCounter]->crossLineTimes[0] == double::MaxValue) {
											  fprintf(absoluteProtocolFile, "NOT STARTED");
										  } else {
											writeTimeByDouble(absoluteProtocolFile,finishProtocolListSorted[competitorsCounter]->crossLineTimes[0], true);
										  }
									  } else {
										writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->startDelay);
									  }
									  fprintf(absoluteProtocolFile,"</td>\n");
								  }

								  if(checkBoxShowLapTimes->Checked) {
									  if(maxNumberOfLaps > 1 || !checkBoxShowFinishTime->Checked) {
								  if(checkBoxAllButtons->Checked) {
									  if(fmod(competitorsCounter,2.0) != 0.0) {
										  fprintf(absoluteProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(oddLineStyle));
									  } else {
										 fprintf(absoluteProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(evenLineStyle));
									  }
									  for(int j = 0;j<maxNumberOfLaps;j++) {
										  double bestFinish = finishProtocolListSorted[competitorsCounter]->finishLapTimes[j];
										  double thisFinish = bestFinish;
										  int placeFinish = 1;
										  double bestLap = finishProtocolListSorted[competitorsCounter]->lapTimes[j];
										  double thisLap = bestLap;
										  int placeLap = 1;

										  for(int lapLeadCounter = 0; lapLeadCounter < numberOfFinishProtocolElements; lapLeadCounter++){
											  if(finishProtocolListSorted[lapLeadCounter]->numberOfLapsFinished > j) {
												  if(finishProtocolListSorted[lapLeadCounter]->lapTimes[j] < thisLap) {
													  placeLap++;
													  if(finishProtocolListSorted[lapLeadCounter]->lapTimes[j] < bestLap) {
														  bestLap = finishProtocolListSorted[lapLeadCounter]->lapTimes[j];
													  }
												  }
												  if(finishProtocolListSorted[lapLeadCounter]->finishLapTimes[j] < thisFinish) {
													  placeFinish++;
													  if(finishProtocolListSorted[lapLeadCounter]->finishLapTimes[j] < bestFinish) {
														  bestFinish = finishProtocolListSorted[lapLeadCounter]->finishLapTimes[j];
													  }
												  }
											  }
										  }
										  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished > j) {
											  fprintf(absoluteProtocolFile,"<td COLSPAN=%d ROWSPAN=1 id=\"%d_Дополнительная %d инфа_%d\" ALIGN=center><FONT SIZE=\"1\">%s", columnsNumber, groupsCounter ,j, competitorsCounter+1,(placeLap==1)?"<B>":"");
											  writeTimeByDouble(absoluteProtocolFile,thisLap-bestLap);
											  fprintf(absoluteProtocolFile,"&nbsp(%d)%s",placeLap,(placeLap==1)?"</B>":"");
											  if(checkBoxLapFinnish->Checked) {
												  fprintf(absoluteProtocolFile,"<BR>%s%s",(placeFinish==1)?"<B>":"", getCharArrayFromString(additionalInfoStyle));
												  writeTimeByDouble(absoluteProtocolFile,thisFinish-bestFinish);
												  fprintf(absoluteProtocolFile,"&nbsp(%d)</FONT>%s",placeFinish, (placeFinish==1)?"<B>":"");
											  }
											  fprintf(absoluteProtocolFile,"</FONT></td>\n");
										  } else {
											  fprintf(absoluteProtocolFile,"<td COLSPAN=%d ROWSPAN=1 id=\"%d_Дополнительная %d инфа_%d\" ALIGN=center></td>", columnsNumber, groupsCounter ,j, competitorsCounter+1);
										  }
									  }
								  }


								  if(numberOfPoints>0 && !isNumberOfTries()) {
									  if(fmod(competitorsCounter,2.0) != 0.0) {
										  fprintf(absoluteProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(oddLineStyle));
									  } else {
										 fprintf(absoluteProtocolFile,"</tr>\n<tr style=\"%s\">\n",getCharArrayFromString(evenLineStyle));
									  }
									  for(int lapsCompetitorCounter = 0;lapsCompetitorCounter <maxNumberOfLaps;lapsCompetitorCounter++) {
										  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished+1>lapsCompetitorCounter && lapsCompetitorCounter < finishProtocolListSorted[competitorsCounter]->numberOfLaps) {
											  for(int cpCounter = 0; cpCounter < numberOfPoints; cpCounter++) {
												  fprintf(absoluteProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\">(", groupsCounter, (lapsCompetitorCounter*(numberOfPoints+1))+cpCounter, competitorsCounter + 1);
												  if(finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished + 1 >lapsCompetitorCounter && lapsCompetitorCounter < maxNumberOfLaps) {
													  if(finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentTimes[cpCounter] != -1) {
														  if(finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentTimes[cpCounter] != -2) {
															writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentTimes[cpCounter]);
														  } else {
															fprintf(absoluteProtocolFile,"<FONT COLOR=\"#FF0000\">Неизвестно</FONT>");
														  }
													  } else {
														fprintf(absoluteProtocolFile,"<FONT COLOR=\"#FF0000\">Неявка</FONT>");
													  }
												  }
											  fprintf(absoluteProtocolFile,")</FONT></td>\n");
											  }
											  if(lapsCompetitorCounter >= finishProtocolListSorted[competitorsCounter]->numberOfLapsFinished){
												  fprintf(absoluteProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\">(<FONT COLOR=\"#FF0000\">Неявка</FONT>)</td>\n", groupsCounter,((lapsCompetitorCounter+1)*(numberOfPoints+1))-1, competitorsCounter + 1);
											  } else {
												  if(finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentCrosses[numberOfPoints-1] == -1) {
													  fprintf(absoluteProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\"><FONT SIZE=\"1\">(<FONT COLOR=\"#FF0000\">Неизвестно</FONT>)</FONT></td>\n", groupsCounter, ((lapsCompetitorCounter+1)*(numberOfPoints+1))-1, competitorsCounter + 1);
												  } else {
													  fprintf(absoluteProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center><FONT SIZE=\"1\">(", groupsCounter, ((lapsCompetitorCounter+1)*(numberOfPoints+1))-1, competitorsCounter + 1);
													  writeTimeByDouble(absoluteProtocolFile, finishProtocolListSorted[competitorsCounter]->crossLineTimes[lapsCompetitorCounter+1] - finishProtocolListSorted[competitorsCounter]->controlPoints[lapsCompetitorCounter]->segmentCrosses[numberOfPoints-1]);
													  fprintf(absoluteProtocolFile,")</FONT></td>\n");
												  }
											  }
										  } else {
											  for(int cpCounter = 0; cpCounter < numberOfPoints+1; cpCounter++) {
												  fprintf(absoluteProtocolFile,"<td id=\"%d_Время %d отрезка_%d\" ALIGN=center></td>\n", groupsCounter, (lapsCompetitorCounter*(numberOfPoints+1))+cpCounter, competitorsCounter + 1);
											  }
										  }
									  }
								  }
								  }	
								  }
							fprintf(absoluteProtocolFile,"</tr>\n");

								  
							  }
						  }
						  fprintf(absoluteProtocolFile,"</table>");
//BOTTOM
							  writeProtocolBottom(absoluteProtocolFile);
//END BOTTOM
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,gcnew String("Exit function \"writeAbsoluteProtocol()\""));
				  }

				  private: inline bool isTheSameCompetitor(FinishProtocolElement* finishElement, FinishCompetitorElement* timePoint) {
							   if(strcmp(finishElement->competitorID, timePoint->competitorID)==0) return true;
							   if(finishElement->stagesNumber != 1) {
								   for(int i = 0;i<finishElement->stagesNumber;i++) {
									   int number = finishElement->competitorNumber + i;
									   if(number.ToString()->Equals(gcnew String(timePoint->competitorID))) {
										   return true;
									   }
							   }
							   }
							   return false;
				  }
		 private: void calculateProtocol(){
					  double registrationPeriod = 0;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_ENTER_FUNCTION,gcnew String("Enter function \"calculateProtocol()\""));
					  try {
						  registrationPeriod = Double::Parse(maskedTextBoxStartRegistrationPeriod->Text);
					  } catch (Object^ e) {
						  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Broken seconds format in StartRegistrationPeriod: ") + maskedTextBoxStartRegistrationPeriod->Text);
					  }
					  finishProtocolList = new FinishProtocolElement*[numberOfStartProtocolElements];
					  numberOfFinishProtocolElements = numberOfStartProtocolElements;
					  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Enter cycle for all competitors in \"calculateProtocol()\""));
					  for(int competitorsCounter = 0;competitorsCounter<numberOfStartProtocolElements;competitorsCounter++) {
						  bool groupStartTimeForCompetitorFound;
						  groupStartTimeForCompetitorFound = false;
						  finishProtocolList[competitorsCounter] = new FinishProtocolElement(startProtocolList[competitorsCounter], checkBoxDisableDNF->Checked, false, numberOfPoints);

					  if(skipFirstLap()) {
						  finishProtocolList[competitorsCounter]->numberOfLaps--;
						  startProtocolList[competitorsCounter]->numberOfLaps--;
						  finishProtocolList[competitorsCounter]->crossLineTimes[0] = double::MaxValue;
						  bool startTimeFound = false;
						  for(int finishCompetitorCounter = 0;finishCompetitorCounter<numberOfCompetitorElements;finishCompetitorCounter++) {
							  if(isTheSameCompetitor(finishProtocolList[competitorsCounter], finishCompetitorList[finishCompetitorCounter])) {
								  if(finishCompetitorList[finishCompetitorCounter]->seconds < finishProtocolList[competitorsCounter]->crossLineTimes[0]) {
									  finishProtocolList[competitorsCounter]->crossLineTimes[0] = finishCompetitorList[finishCompetitorCounter]->seconds;
									  startTimeFound = true;
								  }
							  }
						  }

					  } else {
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Trying to find groupStartTime for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor i.e. group \"") + gcnew String(finishProtocolList[competitorsCounter]->groupID) + gcnew String("\" in \"calculateProtocol()\""));
						  for(int groupsCounter = 0;groupsCounter < numberOfGroups;groupsCounter++) {
							  if(strcmp(finishProtocolList[competitorsCounter]->groupID, groupStartList[groupsCounter]->groupID)==0) {
								  finishProtocolList[competitorsCounter]->crossLineTimes[0] = groupStartList[groupsCounter]->seconds + finishProtocolList[competitorsCounter]->startDelay;
								  groupStartTimeForCompetitorFound = true;
								  break;
							  }
						  }
						  if(groupStartTimeForCompetitorFound) {
							LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("GroupStartTime found for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + "\" competitor i.e. group \"" + gcnew String(finishProtocolList[competitorsCounter]->groupID) + gcnew String("\" and equals \"") + finishProtocolList[competitorsCounter]->crossLineTimes[0].ToString() + gcnew String("\" in \"calculateProtocol()\""));
						  } else {
							LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("GroupStartTime NOT found for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + "\" competitor i.e. group \"" + gcnew String(finishProtocolList[competitorsCounter]->groupID) + gcnew String("\" and equals \"") + finishProtocolList[competitorsCounter]->crossLineTimes[0].ToString() + gcnew String("\" in \"calculateProtocol()\""));
						  }
					  }
					  if(checkBoxStartCheckList->Checked) {
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Processing start check list for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + "\" competitor i.e. that he passed start control not more than " + maskedTextBoxStartRegistrationPeriod->Text + gcnew String(" seconds before group start ") + gcnew String(finishProtocolList[competitorsCounter]->groupID));
						  bool competitorPassedStartCheck = false;
						  for(int checkListCounter = 0;checkListCounter < numberOfStartChecks;checkListCounter++) {
							  if(isTheSameCompetitor(finishProtocolList[competitorsCounter],startCheckList[checkListCounter])) {
								  if(finishProtocolList[competitorsCounter]->crossLineTimes[0] - registrationPeriod < startCheckList[checkListCounter]->seconds) {
									  competitorPassedStartCheck = true;
								  } else {
									  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + "\" passed registration before registration open. See check list string " + (checkListCounter+1));
								  }
							  }
						  }
						  if(!competitorPassedStartCheck) LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + "\" did not pass start registration.");
						  finishProtocolList[competitorsCounter]->disqualified = !competitorPassedStartCheck;
					  }



						  for(int finishCompetitorCounter = 0;finishCompetitorCounter<numberOfCompetitorElements;finishCompetitorCounter++) {
							  if(isTheSameCompetitor(finishProtocolList[competitorsCounter],finishCompetitorList[finishCompetitorCounter])) {
									if(strcmp(finishCompetitorList[finishCompetitorCounter]->action,"DSQ")==0) {
										  finishProtocolList[competitorsCounter]->disqualified = !checkBoxDisableDSQ->Checked;
									}
									if(strcmp(finishCompetitorList[finishCompetitorCounter]->action,"finish")==0) {
										if(finishProtocolList[competitorsCounter]->finished) {
											LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Second finish mark found for competitor ") + gcnew String(finishCompetitorList[finishCompetitorCounter]->competitorID) + gcnew String(" at line ") + (finishCompetitorCounter+1).ToString());
										}
										finishProtocolList[competitorsCounter]->finished = true;
								    }
							  }
						  }
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("Finished or not and disqualified or not for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor successfully calculated \"calculateProtocol()\"")));


					  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Trying to find all crosses control point for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor in \"calculateProtocol()\""));
					  int numberOfCrossesTofind = isNumberOfTries()?finishProtocolList[competitorsCounter]->numberOfLaps*2:finishProtocolList[competitorsCounter]->numberOfLaps+1;

					  double previousFoundCross = finishProtocolList[competitorsCounter]->crossLineTimes[0];
					  double previousLapStart = finishProtocolList[competitorsCounter]->crossLineTimes[0];
					  bool isTryFinish = true;
					  for(int lapsCounter = 1;lapsCounter<numberOfCrossesTofind;lapsCounter++) {
							  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,gcnew String("Trying to find ") + lapsCounter.ToString() +  gcnew String("-th cross control point for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor in \"calculateProtocol()\""));
							  bool nextLapCrossed = false;
							  double nextFoundCross = double::MaxValue;
							  for(int finishCompetitorCounter = 0;finishCompetitorCounter<numberOfCompetitorElements;finishCompetitorCounter++) {
								  if(strcmp(finishCompetitorList[finishCompetitorCounter]->action, "DSQ")!=0 && 
									  isTheSameCompetitor(finishProtocolList[competitorsCounter], finishCompetitorList[finishCompetitorCounter])) {
									  if(previousFoundCross < finishCompetitorList[finishCompetitorCounter]->seconds) {
										  if(finishCompetitorList[finishCompetitorCounter]->seconds < nextFoundCross) {
											  if((isTryFinish || !isNumberOfTries()) && 
												  previousFoundCross > finishCompetitorList[finishCompetitorCounter]->seconds - ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxMinimalTimeForLap->Text))) {
												  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" passed lap in time less than \"Minimal time for lap\". String: ")+ (finishCompetitorCounter+1).ToString());
											  } else {
												  if(!isNumberOfTries() && finishProtocolList[competitorsCounter]->crossLineTimes[0] < finishCompetitorList[finishCompetitorCounter]->seconds - ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxTimeLimit->Text))) {
													  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("Competitor \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" crossed finish line after end of timeLimit. String: ")+ (finishCompetitorCounter+1).ToString());
												  } else {
													  nextFoundCross = finishCompetitorList[finishCompetitorCounter]->seconds;
													  nextLapCrossed = true;
													  if(isNumberOfTries()) {
														  if(isTryFinish) {
															  finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished+1] = 
																  finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished] +
																  nextFoundCross - 
																  previousFoundCross;
														  }
													  } else {
														  finishProtocolList[competitorsCounter]->crossLineTimes[lapsCounter] = finishCompetitorList[finishCompetitorCounter]->seconds;
														  if(finishProtocolList[competitorsCounter]->stagesNumber != 1) {
															  finishProtocolList[competitorsCounter]->lapFinishNumbers[lapsCounter-1] = ProtocolStringParser::getIntByString(finishCompetitorList[finishCompetitorCounter]->competitorID);
														  }
													  }
												  }
											  }
										  }
									  }
								  }
							  }
							  if(nextLapCrossed) {
								  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,lapsCounter.ToString() +  gcnew String("-th of ") + finishProtocolList[competitorsCounter]->numberOfLaps.ToString() +  gcnew String(" cross control point for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor successfully found in \"calculateProtocol()\""));

								  if(!isNumberOfTries() || isTryFinish) {
									  finishProtocolList[competitorsCounter]->numberOfLapsFinished++;
									  previousLapStart = previousFoundCross;
								  }
								  if(!isNumberOfTries() || !isTryFinish) {
									  for(int marshallsCounter = 0;marshallsCounter < numberOfPoints;marshallsCounter++) {
										  for(int penaltiesCount = 0;penaltiesCount < numberOfRemoteElements[marshallsCounter];penaltiesCount++) {
											  if(strcmp(remotePointsList[marshallsCounter][penaltiesCount]->competitorID,finishProtocolList[competitorsCounter]->competitorID)==0 &&
												  remotePointsList[marshallsCounter][penaltiesCount]->seconds>=previousLapStart &&
												  remotePointsList[marshallsCounter][penaltiesCount]->seconds<nextFoundCross) {
												  finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished]+=
													  remotePointsList[marshallsCounter][penaltiesCount]->penalty;
												  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
													  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], "<BR>");
												  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
													  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], remotePointsList[marshallsCounter][penaltiesCount]->action);
												  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
													  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], ":");
												  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
													  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], 
													  LoggerSTC::getCharArrayFromString((gcnew Int32(remotePointsList[marshallsCounter][penaltiesCount]->penalty))->ToString()));
												  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
													  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], "сек");
											  }

										  }
									  }
									  if(finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished] > finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1] + ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxTimeLimit->Text))) {
										  finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished] = finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1] + ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxTimeLimit->Text));
									  }
								  }

								  isTryFinish = !isTryFinish;
								  previousFoundCross = nextFoundCross;

							  } else {
								  if(!finishProtocolList[competitorsCounter]->finished) {
									  LoggerSTC::writeLog(LoggerSTC::STATUS_WARNING,lapsCounter.ToString() +  gcnew String("-th of ") + finishProtocolList[competitorsCounter]->numberOfLaps.ToString() +  gcnew String(" cross control point for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor NOT found in \"calculateProtocol()\""));
								  }
								  break;
							  }
						  }
					  if(isNumberOfTries()) {
						  for(int marshallsCounter = 0;marshallsCounter < numberOfPoints;marshallsCounter++) {
							  for(int penaltiesCount = 0;penaltiesCount < numberOfRemoteElements[marshallsCounter];penaltiesCount++) {
								  if(strcmp(remotePointsList[marshallsCounter][penaltiesCount]->competitorID,finishProtocolList[competitorsCounter]->competitorID)==0 &&
									  remotePointsList[marshallsCounter][penaltiesCount]->seconds>=previousLapStart) {
									  finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished]+=
										  remotePointsList[marshallsCounter][penaltiesCount]->penalty;
									  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
										  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], "<BR>");
									  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
										  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], remotePointsList[marshallsCounter][penaltiesCount]->action);
									  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
										  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], ":");
									  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
										  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], 
										  LoggerSTC::getCharArrayFromString((gcnew Int32(remotePointsList[marshallsCounter][penaltiesCount]->penalty))->ToString()));
									  finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1]=
										  strcat(finishProtocolList[competitorsCounter]->lapPenaltyComment[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1], "сек");
								  }

							  }
						  }
						  if(finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished] > finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1] + ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxTimeLimit->Text))) {
							  finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished] = finishProtocolList[competitorsCounter]->crossLineTimes[finishProtocolList[competitorsCounter]->numberOfLapsFinished-1] + ProtocolStringParser::getIntByString(LoggerSTC::getCharArrayFromString(textBoxTimeLimit->Text));
						  }
					  }

						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("All crosses of control point for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor successfullly found in \"calculateProtocol()\"")));
						  if(useSpiridonovCoefficients()) {
							  if(numberOfPoints != 0) {
								  LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR,gcnew String("!!!Please, do not use Spiridonov's age coefficients option with intermediate control points - this functionality not implemented!!!"));
							  }
							  for(int spiridonovCounter = 0; spiridonovCounter <= finishProtocolList[competitorsCounter]->numberOfLapsFinished;spiridonovCounter++){
								  finishProtocolList[competitorsCounter]->crossLineTimes[spiridonovCounter] /= spiridonov(finishProtocolList[competitorsCounter]->competitorYearOfBirth);
								  finishProtocolList[competitorsCounter]->competitorAdditionalInfo = LoggerSTC::getCharArrayFromString(spiridonov(finishProtocolList[competitorsCounter]->competitorYearOfBirth).ToString());
							  }
						  }
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("Calculate lapTimes and finishLapTimes for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor \"calculateProtocol()\"")));
						  for(int finishedLapsCounter = 0;finishedLapsCounter <finishProtocolList[competitorsCounter]->numberOfLapsFinished; finishedLapsCounter++) {
							  finishProtocolList[competitorsCounter]->lapTimes[finishedLapsCounter] = finishProtocolList[competitorsCounter]->crossLineTimes[finishedLapsCounter+1] - finishProtocolList[competitorsCounter]->crossLineTimes[finishedLapsCounter];
							  finishProtocolList[competitorsCounter]->finishLapTimes[finishedLapsCounter] = finishProtocolList[competitorsCounter]->crossLineTimes[finishedLapsCounter+1] - finishProtocolList[competitorsCounter]->crossLineTimes[0];
						  }
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("lapTimes and finishLapTimes for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor succesfully calculated \"calculateProtocol()\"")));
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("Calculate finished or not and disqualified or not for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor \"calculateProtocol()\"")));
						  if(finishProtocolList[competitorsCounter]->numberOfLapsFinished==finishProtocolList[competitorsCounter]->numberOfLaps) {
							  finishProtocolList[competitorsCounter]->finished = true;
						  }
						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("Analyzing remote points for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor started in \"calculateProtocol()\"")));
//HERE SHOULD BE CHECK FOR EVENT
						  for(int lapsCounter = 0;((lapsCounter < finishProtocolList[competitorsCounter]->numberOfLapsFinished + 1) && (lapsCounter < finishProtocolList[competitorsCounter]->numberOfLaps)); lapsCounter++) {
							  for(int crossPointsCounter = 0; crossPointsCounter < numberOfPoints; crossPointsCounter++) {
								  double nextLapSeconds = double::MaxValue;
								  if(lapsCounter != finishProtocolList[competitorsCounter]->numberOfLapsFinished + 1) {
									  nextLapSeconds = finishProtocolList[competitorsCounter]->crossLineTimes[lapsCounter+1];
								  }
								  for(int counter = 0;counter < numberOfRemoteElements[crossPointsCounter]; counter++){
									  double previousLapSeconds = 0;
									  bool previousFound = false;
									  if(crossPointsCounter == 0) {
										  previousLapSeconds = finishProtocolList[competitorsCounter]->crossLineTimes[lapsCounter];
										  previousFound = true;
									  } else {
										  if(finishProtocolList[competitorsCounter]->controlPoints[lapsCounter]->segmentCrosses[crossPointsCounter-1] == -1) {
											previousLapSeconds = finishProtocolList[competitorsCounter]->crossLineTimes[lapsCounter];
										  } else {
											previousLapSeconds = finishProtocolList[competitorsCounter]->controlPoints[lapsCounter]->segmentCrosses[crossPointsCounter-1];
											previousFound = true;
										  }
									  }
									  double nextSeconds = remotePointsList[crossPointsCounter][counter]->seconds;
									  if(nextSeconds > previousLapSeconds && nextSeconds < nextLapSeconds && 
										  (isTheSameCompetitor(finishProtocolList[competitorsCounter], remotePointsList[crossPointsCounter][counter]))) {
										  finishProtocolList[competitorsCounter]->controlPoints[lapsCounter]->segmentCrosses[crossPointsCounter] = nextSeconds;
										  finishProtocolList[competitorsCounter]->controlPoints[lapsCounter]->segmentFinishes[crossPointsCounter] = nextSeconds - finishProtocolList[competitorsCounter]->crossLineTimes[lapsCounter];
										  if(previousFound) {
											  finishProtocolList[competitorsCounter]->controlPoints[lapsCounter]->segmentTimes[crossPointsCounter] = nextSeconds - previousLapSeconds;
										  } else {
											  finishProtocolList[competitorsCounter]->controlPoints[lapsCounter]->segmentTimes[crossPointsCounter] = -2;
										  }
									  }
								  }
							  }
						  }

						  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("Analyzing remote points for \"") + gcnew String(finishProtocolList[competitorsCounter]->competitorID) + gcnew String("\" competitor finished in \"calculateProtocol()\"")));



					  }

					  LoggerSTC::writeLog(LoggerSTC::STATUS_INFO,(gcnew String("Exit cycle for all competitors in \"calculateProtocol()\"")));
					  LoggerSTC::writeLog(LoggerSTC::STATUS_EXIT_FUNCTION,(gcnew String("Exit function:\"calculateProtocol()\"")));
				  }

				  public: int readStringFromFile(FILE* fileFrom, char* stringTo) {
					  char tempChar;
					  int fscanfResult;
					  for(int i = 0;i<LoggerSTC::numberOfCharsInString;i++) {
						  fscanfResult = fscanf(fileFrom,"%c", &tempChar);
						  if(fscanfResult == EOF) {
							  if(i==0) {
								return EOF;
							  } else {
								  stringTo[i] = 0;
								  return 0;
							  }
						  }
						  if(tempChar == '\n') {
								  stringTo[i] = 0;
								  return 0;
						  }
						  stringTo[i] = tempChar;
						  }
					  return EOF;
				  }

				  public: void writeStringToFile(FILE* fileTo, char* stringTo, bool nextString) {
					  int counter = 0;
					  while(stringTo[counter] != 0) {
						  fprintf(fileTo,"%c", stringTo[counter]);
						  counter++;
					  }
					  if(nextString) {
						fprintf(fileTo,"\n");
					  }
				  }
				  public: void writeStringToFile(FILE* fileTo, char* stringTo) {
					  writeStringToFile(fileTo, stringTo, true);
				  }


						  private: void writeTimeByDouble(FILE* outFile,double doubleTime) {
									   writeTimeByDouble(outFile, doubleTime, false);
								   }

				private: void writeTimeByDouble(FILE* outFile,double doubleTime, bool writeDate) {
							 if(doubleTime > 356.0*24.0*60.0*60.0 && !writeDate) {
			 					 fprintf(outFile, "UNKNOWN");
								 LoggerSTC::writeLog(LoggerSTC::STATUS_ERROR, gcnew String("Output time to write ") + doubleTime.ToString() + gcnew String(" is more than year"));
								 return;
							 }



				 if(doubleTime<0) {
					 doubleTime = -doubleTime;
					 fprintf(outFile, "-");
				 }
				 int numberOfSignsAfterPoint = ProtocolStringParser::getIntByString(getCharArrayFromString(textBoxNumberOfSignsAfterPoint->Text));
				 numberOfSignsAfterPoint = (numberOfSignsAfterPoint>4) ? 4 : numberOfSignsAfterPoint;
				 doubleTime *= pow(10.0,numberOfSignsAfterPoint);
				 doubleTime = Math::Round(doubleTime);
				 int milliseconds = fmod(doubleTime, pow(10.0,numberOfSignsAfterPoint));
				 doubleTime /= pow(10.0,numberOfSignsAfterPoint);
				 int seconds = fmod(doubleTime, 60.0);
				 doubleTime /= 60.0;
				 int minutes = fmod(doubleTime, 60.0);
				 doubleTime /= 60.0;
				 int hours = fmod(doubleTime, 24.0);
				 doubleTime /= 24;
				 int days = doubleTime;
				 if(days!=0) {
					 if(writeDate) {
						 int year = 1970;
						 int month = 1;
						 days++;
						 while(days > DateTime::DaysInMonth(year,1)) {
							 while(month<=12 && days > DateTime::DaysInMonth(year,month)) {
								 days -= DateTime::DaysInMonth(year,month);
								 month++;
							 }
							 if(month==13) {
								 year++;
								 month = 1;
							 } else {
								 break;
							 }
						 }
						 fprintf(outFile, "%d-%d-%d ", year, month, days);
					 } else {
						 char* daysString;
						 if(fmod(days, 100.0) == 1) {
							 daysString = "сутки";
						 } else {
							 daysString = "суток";
						 }
						 fprintf(outFile, "%d %s ",days, daysString);
					 }
				 }
				 printTwoDigits(outFile, hours,':');
				 printTwoDigits(outFile, minutes,':');
				 if(numberOfSignsAfterPoint>0) {

					 printTwoDigits(outFile, seconds,'.');
					 fprintf(outFile, "%d",milliseconds);
				 } else {
					 printTwoDigits(outFile, seconds,0);
				 }
			 }
			 private: void printTwoDigits(FILE* outFile, int valueToPrint, char deliminer) {
						  int valueFirstToPrint = valueToPrint/10;
						  int valueSecondToPrint = valueToPrint- valueFirstToPrint*10;
						  fprintf(outFile,"%d",valueFirstToPrint);
						  fprintf(outFile,"%d",valueSecondToPrint);
						  if(deliminer != 0) 
							 fprintf(outFile,"%c",deliminer);
					  }

private: System::Void buttonAbsoluteProtocol_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveFileDialog^ absoluteProtocolFileDialog = gcnew SaveFileDialog();
			 absoluteProtocolFileDialog->RestoreDirectory = true;
			 absoluteProtocolFileDialog->ShowDialog();
			 if(absoluteProtocolFileDialog->FileName != String::Empty) {
				 textBoAbsoluteProtocol->Text = absoluteProtocolFileDialog->FileName;
			 }
		 }
private: System::Void buttonLogSearch_Click(System::Object^  sender, System::EventArgs^  e) {
			 			 int startPosition;
			 if(listBoxLogger->Items->Count >= 1) {
			 if(listBoxLogger->SelectedItems->Count == 0) {
				 startPosition = 0;
			 } else {
				 startPosition = listBoxLogger->SelectedIndex;
			 }
			 for(int i = startPosition+1;i<listBoxLogger->Items->Count;i++) {
				 if(((String^)(listBoxLogger->Items[i]))->ToLower()->Contains(textBoxLogSearch->Text->ToLower())) {
					 listBoxLogger->SetSelected(i,true);
					 return;
				 }
			 }
//			 MessageBox::Show("End of list reached");
			 for(int i = 0;i<=startPosition;i++) {
				 if(((String^)(listBoxLogger->Items[i]))->ToLower()->Contains(textBoxLogSearch->Text->ToLower())) {
					 listBoxLogger->SetSelected(i,true);
					 return;
				 }
			 }
			 MessageBox::Show("No matches found");
			 } else {
				 MessageBox::Show("No matches found");
			 }

		 }
private: System::Void textBoxLogSearch_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode == Keys::Enter) {
				 buttonLogSearch_Click(sender,e);
			 }
		 }
private: System::Void buttonLoadRaceInfoData_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			 openFileDialog->RestoreDirectory = true;
			 openFileDialog->ShowDialog();
			 if(openFileDialog->FileName != String::Empty) {
				 loadConfig(openFileDialog->FileName);
			 }
		 }
private: System::Void loadTemplate(String^ templateFileName) {
				 FILE* templateFile;
				 if((templateFile = fopen(getCharArrayFromString(templateFileName),"r+"))==NULL) {
					 tableStyle = gcnew String("");
					 topLineStyle = gcnew String("background-color: rgb(175, 175, 175)");
					 evenLineStyle = gcnew String("background-color: rgb(215, 215, 215)");
					 oddLineStyle = gcnew String("background-color: rgb(175, 175, 175)");
					 groupNameStyle = gcnew String("<FONT SIZE=\"4\" COLOR=\"#FF0066\">");
					 additionalTextTopStyle = gcnew String("<FONT SIZE=\"2\" COLOR=\"#339900\">");
					 additionalTextStyle = gcnew String("<FONT SIZE=\"2\" COLOR=\"#339900\">");
					 topTextStyle = gcnew String("<FONT SIZE=\"4\" COLOR=\"\">");
					 additionalInfoTopStyle = "<FONT COLOR=\"#339900\">";
					 additionalInfoStyle = "<FONT COLOR=\"#339900\">";
					 commonStyleText = String::Empty;
					 MessageBox::Show("Unable to open template: \"" + templateFileName + "\". Using default template.");
				 } else {
					 char* tempString = new char[LoggerSTC::numberOfCharsInString];
					 readStringFromFile(templateFile, tempString);
					 tableStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 topLineStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 evenLineStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 oddLineStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 groupNameStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 additionalTextTopStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 additionalTextStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 topTextStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 additionalInfoTopStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 additionalInfoStyle = gcnew String(tempString);
					 readStringFromFile(templateFile, tempString);
					 commonStyleText = gcnew String(tempString);
					 fclose(templateFile);
				 }
		 }

private: System::Void loadConfig(String^ fileName) {

			 checkBoxTimeShift->Checked = false;
			 checkBoxAdditionalInfo->Checked = false;
			 textBoxAdditonalInfo->Text = String::Empty;
			 textBoxReferee->Text = String::Empty;
			 textBoxSecretary->Text = String::Empty;
			 checkBoxShowID->Checked = false;
			 textBoxID->Text = String::Empty;
			 checkBoxShowName->Checked = false;
			 textBoxName->Text = String::Empty;
			 checkBoxShowAge->Checked = false;
			 textBoxAge->Text = String::Empty;
			 checkBoxShowTeam->Checked = false;
			 textBoxTeam->Text = String::Empty;
			 checkBoxShowCity->Checked = false;
			 textBoxCity->Text = String::Empty;
			 checkBoxShowLapTimes->Checked = false;
			 checkBoxHideEmptyColumns->Checked = false;
			 checkBoxButtons->Checked = false;
			 checkBoxAllButtons->Checked = false;
			 checkBoxLapFinnish->Checked = false;
			 checkBoxShowFinishTime->Checked = false;
			 checkBoxTimeDifference->Checked = false;
			 checkBoxNumberOfFinishedLaps->Checked = false;
			 checkBoxShowGroup->Checked = false;
			 textBoxGroup->Text = String::Empty;
			 checkBoxShowPlace->Checked = false;
			 textBoxPlace->Text = String::Empty;
			 checkBoxStratch->Checked = false;
			 checkBoxPrintDNF->Checked = false;
			 checkBoxPrintDNS->Checked = false;
			 checkBoxPrintDSQ->Checked = false;
			 textBoxStartProtocol->Text = String::Empty;
			 textBoxLapName->Text = String::Empty;
			 textBoxGroupTime->Text = String::Empty;
			 textBoxFinishTime->Text = String::Empty;
			 textBoxGroupsProtocol->Text = String::Empty;
			 textBoAbsoluteProtocol->Text = String::Empty;
			 checkBoxDisableDNF->Checked = false;
			 checkBoxDisableDSQ->Checked = false;
			 checkBoxUseInterfaceLogger->Checked = false;
			 checkBoxUseFileLogger->Checked = false;
			 checkBoxErrAndWrnOnly->Checked = false;
			 checkBoxUploadGroups->Checked = false;
			 checkBoxUploadAbsolute->Checked = false;
			 checkBoxRefresh->Checked = false;
			 checkBoxLapsDifference->Checked = false;
			 maskedTextBoxLapsDifference->Text = String::Empty;
			 textBoxBottom->Text = String::Empty;

				 FILE* openRaceInfo;
				 if((openRaceInfo = fopen(getCharArrayFromString(fileName),"r+"))==NULL) {
					 MessageBox::Show("Unable to open file: \"" + fileName + "\".");
				 } else {
					 char* tempString = new char[LoggerSTC::numberOfCharsInString];
					 int loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 if (loadStringResult!=EOF) {
						 textBoxSponsor->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxRaceName->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxRaceDate->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxRacePlace->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxWeather->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxMainReferee->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxAdditionalReferee->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxOrganizator->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxTrackConditions->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxMinimalTimeForLap->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxTimeLimit->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxNumberOfSignsAfterPoint->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }

					 if (loadStringResult!=EOF) {
						 comboBoxRaceType->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Info") == 0) {
							 checkBoxAdditionalInfo->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxAdditonalInfo->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"RefreshProtocol") == 0) {
							 checkBoxRefresh->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 maskedTextBoxRefreshTime->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							timerRefresh->Interval = int::Parse(maskedTextBoxRefreshTime->Text);
							timerRefresh->Enabled = checkBoxRefresh->Checked;
						 }
					 }
					 if (loadStringResult!=EOF) {
						 textBoxReferee->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxSecretary->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"ID") == 0) {
							 checkBoxShowID->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxID->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Name") == 0) {
							 checkBoxShowName->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxName->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Age") == 0) {
							 checkBoxShowAge->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxAge->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Team") == 0) {
							 checkBoxShowTeam->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxTeam->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"City") == 0) {
							 checkBoxShowCity->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxCity->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Laps") == 0) {
							 checkBoxShowLapTimes->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 if(strcmp(tempString,"Lap Name") == 0) {
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
								 textBoxLapName->Text = gcnew String(tempString);
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 }
							 if(strcmp(tempString,"Lap Finish Info") == 0) {
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
								 textBoxLapAdditionalInfo->Text = gcnew String(tempString);
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 }
							 if(strcmp(tempString,"Lap Finish") == 0) {
								 checkBoxLapFinnish->Checked = true;
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 }
							 if(strcmp(tempString,"Hide Empty Columns") == 0) {
								 checkBoxHideEmptyColumns->Checked = true;
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 }
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Buttons") == 0) {
							 checkBoxButtons->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"All Buttons") == 0) {
							 checkBoxAllButtons->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 bool uploadDownloadRequired = false;
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"UploadGroups") == 0) {
							 checkBoxUploadGroups->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 uploadDownloadRequired = true;
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"UploadAbsolute") == 0) {
							 checkBoxUploadAbsolute->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 uploadDownloadRequired = true;
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString, "None") != 0) {
							 uploadDownloadRequired = true;
						 }
						 comboBoxStartListAction->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString, "None") != 0) {
							 uploadDownloadRequired = true;
						 }
						 comboBoxGroupsTimesAction->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString, "None") != 0) {
							 uploadDownloadRequired = true;
						 }
						 comboBoxResultTimesAction->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString, "None") != 0) {
							 uploadDownloadRequired = true;
						 }
						 comboBoxRemotePointsAction->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxFTPPath->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxFTPLogin->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxFTPPassword->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Finish") == 0) {
							 checkBoxShowFinishTime->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 if(strcmp(tempString,"Time Difference") == 0) {
								 checkBoxTimeDifference->Checked = true;
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 }
							 if(strcmp(tempString,"Number Of Laps Finished") == 0) {
								 checkBoxNumberOfFinishedLaps->Checked = true;
								 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 }


						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Group") == 0) {
							 checkBoxShowGroup->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxGroup->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Place") == 0) {
							 checkBoxShowPlace->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxPlace->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"TimeShift") == 0) {
							 checkBoxTimeShift->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 textBoxTimeShift->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Stratch") == 0) {
							 checkBoxStratch->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Print DNF") == 0) {
							 checkBoxPrintDNF->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Print DNS") == 0) {
							 checkBoxPrintDNS->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Print DSQ") == 0) {
							 checkBoxPrintDSQ->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }

					 if (loadStringResult!=EOF) {
						 textBoxStartProtocol->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxGroupTime->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxFinishTime->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxGroupsProtocol->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoAbsoluteProtocol->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxRemotePoints->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 if (loadStringResult!=EOF) {
						 textBoxRemotePointsNumber->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }




					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Disable DNF") == 0) {
							 checkBoxDisableDNF->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Disable DSQ") == 0) {
							 checkBoxDisableDSQ->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Use File Logger") == 0) {
							 checkBoxUseFileLogger->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Use Interface Logger") == 0) {
							 checkBoxUseInterfaceLogger->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Err and Wrn only") == 0) {
							 checkBoxErrAndWrnOnly->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 
					 
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"Laps Difference Erroros") == 0) {
							 checkBoxLapsDifference->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 maskedTextBoxLapsDifference->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 if(strcmp(tempString,"UseStartCheckList") == 0) {
							 checkBoxStartCheckList->Checked = true;
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 comboBoxStartCheckList->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
							 maskedTextBoxStartRegistrationPeriod->Text = gcnew String(tempString);
							 loadStringResult = readStringFromFile(openRaceInfo, tempString);
						 }
					 }
					 if (loadStringResult!=EOF) {
						 textBoxBottom->Text = gcnew String(tempString);
						 loadStringResult = readStringFromFile(openRaceInfo, tempString);
					 }
					 

					 fclose(openRaceInfo);
				 }


		 }
private: System::Void checkBoxShowLapTimes_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 checkBoxLapFinnish->Enabled = checkBoxShowLapTimes->Checked;
			 checkBoxHideEmptyColumns->Enabled = checkBoxShowLapTimes->Checked;
		 }
private: System::Void checkBoxShowID_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxID->Enabled = checkBoxShowID->Checked;
		 }
private: System::Void checkBoxShowName_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxName->Enabled = checkBoxShowName->Checked;
		 }
private: System::Void checkBoxShowAge_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxAge->Enabled = checkBoxShowAge->Checked;
		 }
private: System::Void checkBoxShowTeam_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxTeam->Enabled = checkBoxShowTeam->Checked;
		 }
private: System::Void checkBoxShowCity_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxCity->Enabled = checkBoxShowCity->Checked;
		 }
private: System::Void checkBoxShowFinishTime_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 checkBoxTimeDifference->Enabled = checkBoxShowFinishTime->Checked;
			 checkBoxNumberOfFinishedLaps->Enabled = checkBoxShowFinishTime->Checked;
		 }
private: System::Void checkBoxShowGroup_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxGroup->Enabled = checkBoxShowGroup->Checked;
		 }
private: System::Void checkBoxShowPlace_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxPlace->Enabled = checkBoxShowPlace->Checked;
		 }
private: System::Void checkBoxPrintDNF_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 checkBoxPrintDNS->Enabled = checkBoxPrintDNF->Checked;
		 }
private: System::Void maskedTextBoxRefreshTime_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void checkBoxRefresh_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 maskedTextBoxRefreshTime->Enabled = checkBoxRefresh->Checked;
		 }
private: System::Void buttonRefreshTimeSubmit_Click(System::Object^  sender, System::EventArgs^  e) {
//			 try {
				timerRefresh->Interval = int::Parse(maskedTextBoxRefreshTime->Text);
//			 }catch (Exception e){
//				 MessageBox::Show(gcnew String("Not valid integer number: ") + maskedTextBoxRefreshTime->Text);
//			 }
			 timerRefresh->Enabled = checkBoxRefresh->Checked;
		 }
private: System::Void timerRefresh_Tick(System::Object^  sender, System::EventArgs^  e) {
			 buttonGenerateProtocol_Click(sender, e);
		 }
private: System::Void buttonSaveRaceInfo_Click(System::Object^  sender, System::EventArgs^  e) {
				 FILE* saveRaceInfo;
				 if((saveRaceInfo = fopen("fpg_info.txt","w"))==NULL) {
					 MessageBox::Show("Unable to open file: \"fpg_info.txt\".");
				 } else {
					 char* tempString = new char[LoggerSTC::numberOfCharsInString];
					 tempString = getCharArrayFromString(textBoxSponsor->Text);
					 writeStringToFile(saveRaceInfo, tempString);
					 tempString = getCharArrayFromString(textBoxRaceName->Text);
					 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxRaceDate->Text);
					 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxRacePlace->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxWeather->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxMainReferee->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxAdditionalReferee->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxOrganizator->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxTrackConditions->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxMinimalTimeForLap->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxTimeLimit->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxNumberOfSignsAfterPoint->Text);
						 writeStringToFile(saveRaceInfo, tempString);

						 tempString = getCharArrayFromString(comboBoxRaceType->Text);
						 writeStringToFile(saveRaceInfo, tempString);

						 if(checkBoxAdditionalInfo->Checked) {
							 writeStringToFile(saveRaceInfo, "Info");
							 tempString = getCharArrayFromString(textBoxAdditonalInfo->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxRefresh->Checked) {
							 writeStringToFile(saveRaceInfo, "RefreshProtocol");
							 tempString = getCharArrayFromString(maskedTextBoxRefreshTime->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 tempString = getCharArrayFromString(textBoxReferee->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxSecretary->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 if(checkBoxShowID->Checked) {
							 writeStringToFile(saveRaceInfo, "ID");
							 tempString = getCharArrayFromString(textBoxID->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxShowName->Checked) {
							 writeStringToFile(saveRaceInfo, "Name");
							 tempString = getCharArrayFromString(textBoxName->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxShowAge->Checked) {
							 writeStringToFile(saveRaceInfo, "Age");
							 tempString = getCharArrayFromString(textBoxAge->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxShowTeam->Checked) {
							 writeStringToFile(saveRaceInfo, "Team");
							 tempString = getCharArrayFromString(textBoxTeam->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxShowCity->Checked) {
							 writeStringToFile(saveRaceInfo, "City");
							 tempString = getCharArrayFromString(textBoxCity->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxShowLapTimes->Checked) {
							 writeStringToFile(saveRaceInfo, "Laps");
							 writeStringToFile(saveRaceInfo, "Lap Name");
							 tempString = getCharArrayFromString(textBoxLapName->Text);
							 writeStringToFile(saveRaceInfo, tempString);
							 writeStringToFile(saveRaceInfo, "Lap Finish Info");
							 tempString = getCharArrayFromString(textBoxLapAdditionalInfo->Text);
							 writeStringToFile(saveRaceInfo, tempString);
							 if(checkBoxLapFinnish->Checked) {
								 writeStringToFile(saveRaceInfo, "Lap Finish");
							 }
							 if(checkBoxHideEmptyColumns->Checked) {
								 writeStringToFile(saveRaceInfo, "Hide Empty Columns");
							 }
						 }
						 if(checkBoxButtons->Checked) {
							 writeStringToFile(saveRaceInfo, "Buttons");
						 }
						 if(checkBoxAllButtons->Checked) {
							 writeStringToFile(saveRaceInfo, "All Buttons");
						 }
						 tempString = getCharArrayFromString(gcnew String(checkBoxUploadGroups->Checked ? "UploadGroups\n" :"") + 
							 gcnew String(checkBoxUploadAbsolute->Checked ? "UploadAbsolute\n" :""));
						 writeStringToFile(saveRaceInfo, tempString, false);

						 tempString = getCharArrayFromString(comboBoxStartListAction->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(comboBoxGroupsTimesAction->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(comboBoxResultTimesAction->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(comboBoxRemotePointsAction->Text);
						 writeStringToFile(saveRaceInfo, tempString);

						 tempString = getCharArrayFromString(textBoxFTPPath->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxFTPLogin->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxFTPPassword->Text);
						 writeStringToFile(saveRaceInfo, tempString);

						 if(checkBoxShowFinishTime->Checked) {
							 writeStringToFile(saveRaceInfo, "Finish");
							 if(checkBoxTimeDifference->Checked) {
								 writeStringToFile(saveRaceInfo, "Time Difference");
							 }
							 if(checkBoxNumberOfFinishedLaps->Checked) {
								 writeStringToFile(saveRaceInfo, "Number Of Laps Finished");
							 }
						 }
						 if(checkBoxShowGroup->Checked) {
							 writeStringToFile(saveRaceInfo, "Group");
							 tempString = getCharArrayFromString(textBoxGroup->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxShowPlace->Checked) {
							 writeStringToFile(saveRaceInfo, "Place");
							 tempString = getCharArrayFromString(textBoxPlace->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
					 if (checkBoxTimeShift->Checked) {
							 writeStringToFile(saveRaceInfo, "TimeShift");
							 tempString = getCharArrayFromString(textBoxTimeShift->Text);
							 writeStringToFile(saveRaceInfo, tempString);
					 }
						 if(checkBoxStratch->Checked) {
							 writeStringToFile(saveRaceInfo, "Stratch");
						 }
						 if(checkBoxPrintDNF->Checked) {
							 writeStringToFile(saveRaceInfo, "Print DNF");
						 }
						 if(checkBoxPrintDNS->Checked) {
							 writeStringToFile(saveRaceInfo, "Print DNS");
						 }
						 if(checkBoxPrintDSQ->Checked) {
							 writeStringToFile(saveRaceInfo, "Print DSQ");
						 }
						 tempString = getCharArrayFromString(textBoxStartProtocol->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxGroupTime->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxFinishTime->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxGroupsProtocol->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoAbsoluteProtocol->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxRemotePoints->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 tempString = getCharArrayFromString(textBoxRemotePointsNumber->Text);
						 writeStringToFile(saveRaceInfo, tempString);
						 if(checkBoxDisableDNF->Checked) {
							 writeStringToFile(saveRaceInfo, "Disable DNF");
						 }
						 if(checkBoxDisableDSQ->Checked) {
							 writeStringToFile(saveRaceInfo, "Disable DSQ");
						 }
						 if(checkBoxUseFileLogger->Checked) {
							 writeStringToFile(saveRaceInfo, "Use File Logger");
						 }
						 if(checkBoxUseInterfaceLogger->Checked) {
							 writeStringToFile(saveRaceInfo, "Use Interface Logger");
						 }
						 if(checkBoxErrAndWrnOnly->Checked) {
							 writeStringToFile(saveRaceInfo, "Err and Wrn only");
						 }
						 if(checkBoxLapsDifference->Checked) {
							 writeStringToFile(saveRaceInfo, "Laps Difference Erroros");
							 tempString = getCharArrayFromString(maskedTextBoxLapsDifference->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 if(checkBoxStartCheckList->Checked) {
							 writeStringToFile(saveRaceInfo, "UseStartCheckList");
							 tempString = getCharArrayFromString(comboBoxStartCheckList->Text);
							 writeStringToFile(saveRaceInfo, tempString);
							 tempString = getCharArrayFromString(maskedTextBoxStartRegistrationPeriod->Text);
							 writeStringToFile(saveRaceInfo, tempString);
						 }
						 tempString = getCharArrayFromString(textBoxBottom->Text);
						 writeStringToFile(saveRaceInfo, tempString);

					 fclose(saveRaceInfo);
				 }

		 }
private: System::Void buttonRemotePoints_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ remotePointsFileDialog = gcnew OpenFileDialog();
			 remotePointsFileDialog->RestoreDirectory = true;
			 remotePointsFileDialog->ShowDialog();
			 if(remotePointsFileDialog->FileName != String::Empty) {
				 textBoxRemotePoints->Text = remotePointsFileDialog->FileName->Substring(0,remotePointsFileDialog->FileName->LastIndexOf("\\")+1);
			 }

		 }
private: System::Void checkBoxUploadDownload_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 enableDisableFTP();
		 }
private: System::Void enableDisableFTP() {
			 bool enableFTP = checkBoxStartCheckList->Checked || checkBoxUploadGroups->Checked || 
				 checkBoxUploadAbsolute->Checked || 
				 downloadStart || downloadResults || 
				 downloadGroups || downloadRemote;
			 textBoxFTPPath->Enabled = enableFTP;
			 textBoxFTPPassword->Enabled = enableFTP;
			 textBoxFTPLogin->Enabled = enableFTP;
		 }
private: System::Void checkBoxShowLoginPassword_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 textBoxFTPLogin->Visible = checkBoxShowLoginPassword->Checked;
			 textBoxFTPPassword->Visible = checkBoxShowLoginPassword->Checked;
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 loadConfig("fpg_info.txt");
			 loadTemplate("template.html");
		 }
private: System::Void checkBoxLapsDifference_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 maskedTextBoxLapsDifference->Enabled = checkBoxLapsDifference->Checked;
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void comboBoxStartListAction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 downloadStart = downloadRequired(comboBoxStartListAction);
			 if (comboBoxStartListAction->Text == downloadReplace && MessageBox::Show("Are you sure reload start list (old file version will be deleted)?","Warning!",MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::No) {
				 comboBoxStartListAction->Text = downloadMerge;
			 }
			 enableDisableFTP();
		 }
private: System::Void comboBoxGroupsTimesAction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 downloadGroups = downloadRequired(comboBoxGroupsTimesAction);
			 if (comboBoxGroupsTimesAction->Text == downloadReplace && MessageBox::Show("Are you sure reload group times (old file version will be deleted)?","Warning!",MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::No) {
				 comboBoxGroupsTimesAction->Text = downloadMerge;
			 }
			 enableDisableFTP();
		 }

private: System::Void checkBoxUploadAbsolute_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 enableDisableFTP();
		 }
private: System::Void comboBoxResultTimesAction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 downloadResults = downloadRequired(comboBoxResultTimesAction);
			 if (comboBoxResultTimesAction->Text == downloadReplace && MessageBox::Show("Are you sure reload result times (old file version will be deleted)?","Warning!",MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::No) {
				 comboBoxResultTimesAction->Text = downloadMerge;
			 }
			 enableDisableFTP();
		 }
private: System::Void comboBoxRemotePointsAction_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 downloadRemote = downloadRequired(comboBoxRemotePointsAction);
			 if (comboBoxRemotePointsAction->Text == downloadReplace && MessageBox::Show("Are you sure reload remote points (old file version will be deleted)?","Warning!",MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::No) {
				 comboBoxRemotePointsAction->Text = downloadMerge;
			 }
			 enableDisableFTP();
		 }
private: System::Void checkBoxStartCheckList_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 comboBoxStartCheckList->Enabled = checkBoxStartCheckList->Checked;
			 maskedTextBoxStartRegistrationPeriod->Enabled = checkBoxStartCheckList->Checked;
			 enableDisableFTP();
		 }
};


}

