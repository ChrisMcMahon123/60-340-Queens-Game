#include <windows.h>
#include "mcmah113PlayerNameDialog.h"

namespace mcmah113Assignment2 {

	using namespace System;
	using namespace System::Timers;
	using namespace System::Media;
	using namespace System::Windows;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing;

	public ref class mcmah113Chessboard : public System::Windows::Forms::Form {
	
	private: Dictionary<String^,bool> ^ queenLocations = gcnew Dictionary<String^, bool>();
	private: List<String^>^ keysList = gcnew List<String^>();
	private: int numOfSquares = 64;
	private: int squaresPerRow = (int)Math::Sqrt(numOfSquares);
	private: String^ locations = "ABCDEFGH";
	private: int numQueens = 0;
	private: int time = 0;

	private: System::Windows::Forms::Panel^  panelChessboard;
	private: System::Windows::Forms::PictureBox^  A7;
	private: System::Windows::Forms::PictureBox^  A8;
	private: System::Windows::Forms::PictureBox^  A6;
	private: System::Windows::Forms::PictureBox^  A5;
	private: System::Windows::Forms::PictureBox^  A4;
	private: System::Windows::Forms::PictureBox^  A3;
	private: System::Windows::Forms::PictureBox^  A2;
	private: System::Windows::Forms::PictureBox^  A1;
	private: System::Windows::Forms::PictureBox^  B8;
	private: System::Windows::Forms::PictureBox^  B7;
	private: System::Windows::Forms::PictureBox^  B6;
	private: System::Windows::Forms::PictureBox^  B5;
	private: System::Windows::Forms::PictureBox^  B4;
	private: System::Windows::Forms::PictureBox^  B3;
	private: System::Windows::Forms::PictureBox^  B2;
	private: System::Windows::Forms::PictureBox^  B1;
	private: System::Windows::Forms::PictureBox^  C8;
	private: System::Windows::Forms::PictureBox^  C7;
	private: System::Windows::Forms::PictureBox^  C6;
	private: System::Windows::Forms::PictureBox^  C5;
	private: System::Windows::Forms::PictureBox^  C4;
	private: System::Windows::Forms::PictureBox^  C3;
	private: System::Windows::Forms::PictureBox^  C2;
	private: System::Windows::Forms::PictureBox^  C1;
	private: System::Windows::Forms::PictureBox^  D8;
	private: System::Windows::Forms::PictureBox^  D7;
	private: System::Windows::Forms::PictureBox^  D6;
	private: System::Windows::Forms::PictureBox^  D5;
	private: System::Windows::Forms::PictureBox^  D4;
	private: System::Windows::Forms::PictureBox^  D3;
	private: System::Windows::Forms::PictureBox^  D2;
	private: System::Windows::Forms::PictureBox^  D1;
	private: System::Windows::Forms::PictureBox^  E8;
	private: System::Windows::Forms::PictureBox^  E7;
	private: System::Windows::Forms::PictureBox^  E6;
	private: System::Windows::Forms::PictureBox^  E5;
	private: System::Windows::Forms::PictureBox^  E4;
	private: System::Windows::Forms::PictureBox^  E3;
	private: System::Windows::Forms::PictureBox^  E2;
	private: System::Windows::Forms::PictureBox^  E1;
	private: System::Windows::Forms::PictureBox^  F8;
	private: System::Windows::Forms::PictureBox^  F7;
	private: System::Windows::Forms::PictureBox^  F6;
	private: System::Windows::Forms::PictureBox^  F5;
	private: System::Windows::Forms::PictureBox^  F4;
	private: System::Windows::Forms::PictureBox^  F3;
	private: System::Windows::Forms::PictureBox^  F2;
	private: System::Windows::Forms::PictureBox^  F1;
	private: System::Windows::Forms::PictureBox^  G8;
	private: System::Windows::Forms::PictureBox^  G7;
	private: System::Windows::Forms::PictureBox^  G6;
	private: System::Windows::Forms::PictureBox^  G5;
	private: System::Windows::Forms::PictureBox^  G4;
	private: System::Windows::Forms::PictureBox^  G3;
	private: System::Windows::Forms::PictureBox^  G2;
	private: System::Windows::Forms::PictureBox^  G1;
	private: System::Windows::Forms::PictureBox^  H8;
	private: System::Windows::Forms::PictureBox^  H7;
	private: System::Windows::Forms::PictureBox^  H6;
	private: System::Windows::Forms::PictureBox^  H5;
	private: System::Windows::Forms::PictureBox^  H4;
	private: System::Windows::Forms::PictureBox^  H3;
	private: System::Windows::Forms::PictureBox^  H2;
	private: System::Windows::Forms::PictureBox^  H1;
	private: System::Windows::Forms::Label^  labelPlayerValue;
	private: System::Windows::Forms::Label^  labelPlayer;
	private: System::Windows::Forms::Timer^  timerGame;
	public: System::Windows::Forms::PictureBox^  pictureBoxChessboard;
	private:

	private:

	public:
		mcmah113Chessboard(void) {
			InitializeComponent();

			//set the labels to their default values and disable all game inputs
			for (int i = 0; i < squaresPerRow; i++) {
				for (int j = 0; j < squaresPerRow; j++) {
					String^ key = locations[i] + (j + 1).ToString();
					keysList->Add(key);
					queenLocations->Add((key), false);
					//System::Diagnostics::Debug::WriteLine("Key: " + key + " = " + queenLocations[key]);
				}
			}

			labelPlayerValue->Text = "";
			labelInputResponse->Text = "";
			buttonEnterQueen->Enabled = false;
			buttonRemoveQueen->Enabled = false;
			textBoxQuadrant->Enabled = false;
			//System::Diagnostics::Debug::WriteLine("Dictionary Size: " + queenLocations->Count);
		}

	protected:
		~mcmah113Chessboard() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonClose;
	private: System::Windows::Forms::Button^  buttonNewGame;
	private: System::Windows::Forms::Button^  buttonRemoveQueen;
	private: System::Windows::Forms::Button^  buttonEnterQueen;
	private: System::Windows::Forms::Label^  labelInputResponse;
	private: System::Windows::Forms::TextBox^  textBoxQuadrant;
	private: System::Windows::Forms::PictureBox^  pictureBoxGameResponse;

	private: System::Windows::Forms::Label^  labelTimeText;
	private: System::Windows::Forms::Label^  labelTimeValue;
	private: System::Windows::Forms::Label^  labelScoreValue;
	private: System::Windows::Forms::Label^  labelScoreText;
	private: System::Windows::Forms::Label^  labelInstructions;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::ComponentModel::IContainer^  components;
	private:
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mcmah113Chessboard::typeid));
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->buttonNewGame = (gcnew System::Windows::Forms::Button());
			this->buttonRemoveQueen = (gcnew System::Windows::Forms::Button());
			this->buttonEnterQueen = (gcnew System::Windows::Forms::Button());
			this->labelInputResponse = (gcnew System::Windows::Forms::Label());
			this->textBoxQuadrant = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxGameResponse = (gcnew System::Windows::Forms::PictureBox());
			this->labelTimeText = (gcnew System::Windows::Forms::Label());
			this->labelTimeValue = (gcnew System::Windows::Forms::Label());
			this->labelScoreValue = (gcnew System::Windows::Forms::Label());
			this->labelScoreText = (gcnew System::Windows::Forms::Label());
			this->labelInstructions = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panelChessboard = (gcnew System::Windows::Forms::Panel());
			this->A7 = (gcnew System::Windows::Forms::PictureBox());
			this->A8 = (gcnew System::Windows::Forms::PictureBox());
			this->A6 = (gcnew System::Windows::Forms::PictureBox());
			this->A5 = (gcnew System::Windows::Forms::PictureBox());
			this->A4 = (gcnew System::Windows::Forms::PictureBox());
			this->A3 = (gcnew System::Windows::Forms::PictureBox());
			this->A2 = (gcnew System::Windows::Forms::PictureBox());
			this->A1 = (gcnew System::Windows::Forms::PictureBox());
			this->B8 = (gcnew System::Windows::Forms::PictureBox());
			this->B7 = (gcnew System::Windows::Forms::PictureBox());
			this->B6 = (gcnew System::Windows::Forms::PictureBox());
			this->B5 = (gcnew System::Windows::Forms::PictureBox());
			this->B4 = (gcnew System::Windows::Forms::PictureBox());
			this->B3 = (gcnew System::Windows::Forms::PictureBox());
			this->B2 = (gcnew System::Windows::Forms::PictureBox());
			this->B1 = (gcnew System::Windows::Forms::PictureBox());
			this->C8 = (gcnew System::Windows::Forms::PictureBox());
			this->C7 = (gcnew System::Windows::Forms::PictureBox());
			this->C6 = (gcnew System::Windows::Forms::PictureBox());
			this->C5 = (gcnew System::Windows::Forms::PictureBox());
			this->C4 = (gcnew System::Windows::Forms::PictureBox());
			this->C3 = (gcnew System::Windows::Forms::PictureBox());
			this->C2 = (gcnew System::Windows::Forms::PictureBox());
			this->C1 = (gcnew System::Windows::Forms::PictureBox());
			this->D8 = (gcnew System::Windows::Forms::PictureBox());
			this->D7 = (gcnew System::Windows::Forms::PictureBox());
			this->D6 = (gcnew System::Windows::Forms::PictureBox());
			this->D5 = (gcnew System::Windows::Forms::PictureBox());
			this->D4 = (gcnew System::Windows::Forms::PictureBox());
			this->D3 = (gcnew System::Windows::Forms::PictureBox());
			this->D2 = (gcnew System::Windows::Forms::PictureBox());
			this->D1 = (gcnew System::Windows::Forms::PictureBox());
			this->E8 = (gcnew System::Windows::Forms::PictureBox());
			this->E7 = (gcnew System::Windows::Forms::PictureBox());
			this->E6 = (gcnew System::Windows::Forms::PictureBox());
			this->E5 = (gcnew System::Windows::Forms::PictureBox());
			this->E4 = (gcnew System::Windows::Forms::PictureBox());
			this->E3 = (gcnew System::Windows::Forms::PictureBox());
			this->E2 = (gcnew System::Windows::Forms::PictureBox());
			this->E1 = (gcnew System::Windows::Forms::PictureBox());
			this->F8 = (gcnew System::Windows::Forms::PictureBox());
			this->F7 = (gcnew System::Windows::Forms::PictureBox());
			this->F6 = (gcnew System::Windows::Forms::PictureBox());
			this->F5 = (gcnew System::Windows::Forms::PictureBox());
			this->F4 = (gcnew System::Windows::Forms::PictureBox());
			this->F3 = (gcnew System::Windows::Forms::PictureBox());
			this->F2 = (gcnew System::Windows::Forms::PictureBox());
			this->F1 = (gcnew System::Windows::Forms::PictureBox());
			this->G8 = (gcnew System::Windows::Forms::PictureBox());
			this->G7 = (gcnew System::Windows::Forms::PictureBox());
			this->G6 = (gcnew System::Windows::Forms::PictureBox());
			this->G5 = (gcnew System::Windows::Forms::PictureBox());
			this->G4 = (gcnew System::Windows::Forms::PictureBox());
			this->G3 = (gcnew System::Windows::Forms::PictureBox());
			this->G2 = (gcnew System::Windows::Forms::PictureBox());
			this->G1 = (gcnew System::Windows::Forms::PictureBox());
			this->H8 = (gcnew System::Windows::Forms::PictureBox());
			this->H7 = (gcnew System::Windows::Forms::PictureBox());
			this->H6 = (gcnew System::Windows::Forms::PictureBox());
			this->H5 = (gcnew System::Windows::Forms::PictureBox());
			this->H4 = (gcnew System::Windows::Forms::PictureBox());
			this->H3 = (gcnew System::Windows::Forms::PictureBox());
			this->H2 = (gcnew System::Windows::Forms::PictureBox());
			this->H1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxChessboard = (gcnew System::Windows::Forms::PictureBox());
			this->labelPlayerValue = (gcnew System::Windows::Forms::Label());
			this->labelPlayer = (gcnew System::Windows::Forms::Label());
			this->timerGame = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGameResponse))->BeginInit();
			this->panelChessboard->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChessboard))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonClose
			// 
			this->buttonClose->Location = System::Drawing::Point(655, 472);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(117, 34);
			this->buttonClose->TabIndex = 0;
			this->buttonClose->Text = L"Close";
			this->buttonClose->UseVisualStyleBackColor = true;
			this->buttonClose->Click += gcnew System::EventHandler(this, &mcmah113Chessboard::buttonClose_Click);
			// 
			// buttonNewGame
			// 
			this->buttonNewGame->Location = System::Drawing::Point(528, 472);
			this->buttonNewGame->Name = L"buttonNewGame";
			this->buttonNewGame->Size = System::Drawing::Size(117, 34);
			this->buttonNewGame->TabIndex = 445;
			this->buttonNewGame->Text = L"New Game";
			this->buttonNewGame->UseVisualStyleBackColor = true;
			this->buttonNewGame->Click += gcnew System::EventHandler(this, &mcmah113Chessboard::buttonNewGame_Click);
			// 
			// buttonRemoveQueen
			// 
			this->buttonRemoveQueen->Location = System::Drawing::Point(655, 415);
			this->buttonRemoveQueen->Name = L"buttonRemoveQueen";
			this->buttonRemoveQueen->Size = System::Drawing::Size(117, 34);
			this->buttonRemoveQueen->TabIndex = 446;
			this->buttonRemoveQueen->Text = L"Remove Queen";
			this->buttonRemoveQueen->UseVisualStyleBackColor = true;
			this->buttonRemoveQueen->Click += gcnew System::EventHandler(this, &mcmah113Chessboard::buttonRemoveQueen_Click);
			// 
			// buttonEnterQueen
			// 
			this->buttonEnterQueen->Location = System::Drawing::Point(528, 415);
			this->buttonEnterQueen->Name = L"buttonEnterQueen";
			this->buttonEnterQueen->Size = System::Drawing::Size(117, 34);
			this->buttonEnterQueen->TabIndex = 447;
			this->buttonEnterQueen->Text = L"Add Queen";
			this->buttonEnterQueen->UseVisualStyleBackColor = true;
			this->buttonEnterQueen->Click += gcnew System::EventHandler(this, &mcmah113Chessboard::buttonEnterQueen_Click);
			// 
			// labelInputResponse
			// 
			this->labelInputResponse->AutoSize = true;
			this->labelInputResponse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelInputResponse->Location = System::Drawing::Point(553, 379);
			this->labelInputResponse->Name = L"labelInputResponse";
			this->labelInputResponse->Size = System::Drawing::Size(83, 18);
			this->labelInputResponse->TabIndex = 448;
			this->labelInputResponse->Text = L"Debug Text";
			this->labelInputResponse->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxQuadrant
			// 
			this->textBoxQuadrant->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxQuadrant->Location = System::Drawing::Point(556, 350);
			this->textBoxQuadrant->Name = L"textBoxQuadrant";
			this->textBoxQuadrant->Size = System::Drawing::Size(189, 26);
			this->textBoxQuadrant->TabIndex = 449;
			// 
			// pictureBoxGameResponse
			// 
			this->pictureBoxGameResponse->Location = System::Drawing::Point(556, 123);
			this->pictureBoxGameResponse->Name = L"pictureBoxGameResponse";
			this->pictureBoxGameResponse->Size = System::Drawing::Size(116, 108);
			this->pictureBoxGameResponse->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxGameResponse->TabIndex = 450;
			this->pictureBoxGameResponse->TabStop = false;
			// 
			// labelTimeText
			// 
			this->labelTimeText->AutoSize = true;
			this->labelTimeText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTimeText->Location = System::Drawing::Point(552, 45);
			this->labelTimeText->Name = L"labelTimeText";
			this->labelTimeText->Size = System::Drawing::Size(58, 24);
			this->labelTimeText->TabIndex = 451;
			this->labelTimeText->Text = L"Time:";
			// 
			// labelTimeValue
			// 
			this->labelTimeValue->AutoSize = true;
			this->labelTimeValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTimeValue->Location = System::Drawing::Point(651, 45);
			this->labelTimeValue->Name = L"labelTimeValue";
			this->labelTimeValue->Size = System::Drawing::Size(20, 24);
			this->labelTimeValue->TabIndex = 452;
			this->labelTimeValue->Text = L"0";
			// 
			// labelScoreValue
			// 
			this->labelScoreValue->AutoSize = true;
			this->labelScoreValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelScoreValue->Location = System::Drawing::Point(651, 79);
			this->labelScoreValue->Name = L"labelScoreValue";
			this->labelScoreValue->Size = System::Drawing::Size(20, 24);
			this->labelScoreValue->TabIndex = 454;
			this->labelScoreValue->Text = L"0";
			// 
			// labelScoreText
			// 
			this->labelScoreText->AutoSize = true;
			this->labelScoreText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelScoreText->Location = System::Drawing::Point(552, 79);
			this->labelScoreText->Name = L"labelScoreText";
			this->labelScoreText->Size = System::Drawing::Size(65, 24);
			this->labelScoreText->TabIndex = 453;
			this->labelScoreText->Text = L"Score:";
			// 
			// labelInstructions
			// 
			this->labelInstructions->AutoSize = true;
			this->labelInstructions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelInstructions->Location = System::Drawing::Point(552, 234);
			this->labelInstructions->Name = L"labelInstructions";
			this->labelInstructions->Size = System::Drawing::Size(100, 24);
			this->labelInstructions->TabIndex = 455;
			this->labelInstructions->Text = L"Instruction:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(553, 261);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 18);
			this->label1->TabIndex = 456;
			this->label1->Text = L"Add or remove a queen by";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(553, 288);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 18);
			this->label2->TabIndex = 457;
			this->label2->Text = L"inputting the corrosponding";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(553, 317);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(192, 18);
			this->label3->TabIndex = 458;
			this->label3->Text = L"quadrant on the chessboard";
			// 
			// panelChessboard
			// 
			this->panelChessboard->Controls->Add(this->A7);
			this->panelChessboard->Controls->Add(this->A8);
			this->panelChessboard->Controls->Add(this->A6);
			this->panelChessboard->Controls->Add(this->A5);
			this->panelChessboard->Controls->Add(this->A4);
			this->panelChessboard->Controls->Add(this->A3);
			this->panelChessboard->Controls->Add(this->A2);
			this->panelChessboard->Controls->Add(this->A1);
			this->panelChessboard->Controls->Add(this->B8);
			this->panelChessboard->Controls->Add(this->B7);
			this->panelChessboard->Controls->Add(this->B6);
			this->panelChessboard->Controls->Add(this->B5);
			this->panelChessboard->Controls->Add(this->B4);
			this->panelChessboard->Controls->Add(this->B3);
			this->panelChessboard->Controls->Add(this->B2);
			this->panelChessboard->Controls->Add(this->B1);
			this->panelChessboard->Controls->Add(this->C8);
			this->panelChessboard->Controls->Add(this->C7);
			this->panelChessboard->Controls->Add(this->C6);
			this->panelChessboard->Controls->Add(this->C5);
			this->panelChessboard->Controls->Add(this->C4);
			this->panelChessboard->Controls->Add(this->C3);
			this->panelChessboard->Controls->Add(this->C2);
			this->panelChessboard->Controls->Add(this->C1);
			this->panelChessboard->Controls->Add(this->D8);
			this->panelChessboard->Controls->Add(this->D7);
			this->panelChessboard->Controls->Add(this->D6);
			this->panelChessboard->Controls->Add(this->D5);
			this->panelChessboard->Controls->Add(this->D4);
			this->panelChessboard->Controls->Add(this->D3);
			this->panelChessboard->Controls->Add(this->D2);
			this->panelChessboard->Controls->Add(this->D1);
			this->panelChessboard->Controls->Add(this->E8);
			this->panelChessboard->Controls->Add(this->E7);
			this->panelChessboard->Controls->Add(this->E6);
			this->panelChessboard->Controls->Add(this->E5);
			this->panelChessboard->Controls->Add(this->E4);
			this->panelChessboard->Controls->Add(this->E3);
			this->panelChessboard->Controls->Add(this->E2);
			this->panelChessboard->Controls->Add(this->E1);
			this->panelChessboard->Controls->Add(this->F8);
			this->panelChessboard->Controls->Add(this->F7);
			this->panelChessboard->Controls->Add(this->F6);
			this->panelChessboard->Controls->Add(this->F5);
			this->panelChessboard->Controls->Add(this->F4);
			this->panelChessboard->Controls->Add(this->F3);
			this->panelChessboard->Controls->Add(this->F2);
			this->panelChessboard->Controls->Add(this->F1);
			this->panelChessboard->Controls->Add(this->G8);
			this->panelChessboard->Controls->Add(this->G7);
			this->panelChessboard->Controls->Add(this->G6);
			this->panelChessboard->Controls->Add(this->G5);
			this->panelChessboard->Controls->Add(this->G4);
			this->panelChessboard->Controls->Add(this->G3);
			this->panelChessboard->Controls->Add(this->G2);
			this->panelChessboard->Controls->Add(this->G1);
			this->panelChessboard->Controls->Add(this->H8);
			this->panelChessboard->Controls->Add(this->H7);
			this->panelChessboard->Controls->Add(this->H6);
			this->panelChessboard->Controls->Add(this->H5);
			this->panelChessboard->Controls->Add(this->H4);
			this->panelChessboard->Controls->Add(this->H3);
			this->panelChessboard->Controls->Add(this->H2);
			this->panelChessboard->Controls->Add(this->H1);
			this->panelChessboard->Controls->Add(this->pictureBoxChessboard);
			this->panelChessboard->Location = System::Drawing::Point(1, 1);
			this->panelChessboard->Name = L"panelChessboard";
			this->panelChessboard->Size = System::Drawing::Size(521, 517);
			this->panelChessboard->TabIndex = 459;
			// 
			// A7
			// 
			this->A7->AccessibleName = L"A7";
			this->A7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A7.Image")));
			this->A7->Location = System::Drawing::Point(46, 101);
			this->A7->Margin = System::Windows::Forms::Padding(1);
			this->A7->MaximumSize = System::Drawing::Size(45, 45);
			this->A7->MinimumSize = System::Drawing::Size(20, 20);
			this->A7->Name = L"A7";
			this->A7->Size = System::Drawing::Size(45, 45);
			this->A7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A7->TabIndex = 452;
			this->A7->TabStop = false;
			this->A7->Visible = false;
			// 
			// A8
			// 
			this->A8->AccessibleName = L"A8";
			this->A8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A8.Image")));
			this->A8->Location = System::Drawing::Point(46, 44);
			this->A8->Margin = System::Windows::Forms::Padding(1);
			this->A8->MaximumSize = System::Drawing::Size(45, 45);
			this->A8->MinimumSize = System::Drawing::Size(20, 20);
			this->A8->Name = L"A8";
			this->A8->Size = System::Drawing::Size(45, 45);
			this->A8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A8->TabIndex = 453;
			this->A8->TabStop = false;
			this->A8->Visible = false;
			// 
			// A6
			// 
			this->A6->AccessibleName = L"A6";
			this->A6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A6.Image")));
			this->A6->Location = System::Drawing::Point(45, 155);
			this->A6->Margin = System::Windows::Forms::Padding(1);
			this->A6->MaximumSize = System::Drawing::Size(45, 45);
			this->A6->MinimumSize = System::Drawing::Size(20, 20);
			this->A6->Name = L"A6";
			this->A6->Size = System::Drawing::Size(45, 45);
			this->A6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A6->TabIndex = 451;
			this->A6->TabStop = false;
			this->A6->Visible = false;
			// 
			// A5
			// 
			this->A5->AccessibleName = L"A5";
			this->A5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A5.Image")));
			this->A5->Location = System::Drawing::Point(46, 212);
			this->A5->Margin = System::Windows::Forms::Padding(1);
			this->A5->MaximumSize = System::Drawing::Size(45, 45);
			this->A5->MinimumSize = System::Drawing::Size(20, 20);
			this->A5->Name = L"A5";
			this->A5->Size = System::Drawing::Size(45, 45);
			this->A5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A5->TabIndex = 450;
			this->A5->TabStop = false;
			this->A5->Visible = false;
			// 
			// A4
			// 
			this->A4->AccessibleName = L"A4";
			this->A4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A4.Image")));
			this->A4->Location = System::Drawing::Point(46, 260);
			this->A4->Margin = System::Windows::Forms::Padding(1);
			this->A4->MaximumSize = System::Drawing::Size(45, 45);
			this->A4->MinimumSize = System::Drawing::Size(20, 20);
			this->A4->Name = L"A4";
			this->A4->Size = System::Drawing::Size(45, 45);
			this->A4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A4->TabIndex = 449;
			this->A4->TabStop = false;
			this->A4->Visible = false;
			// 
			// A3
			// 
			this->A3->AccessibleName = L"A3";
			this->A3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A3.Image")));
			this->A3->Location = System::Drawing::Point(46, 316);
			this->A3->Margin = System::Windows::Forms::Padding(1);
			this->A3->MaximumSize = System::Drawing::Size(45, 45);
			this->A3->MinimumSize = System::Drawing::Size(20, 20);
			this->A3->Name = L"A3";
			this->A3->Size = System::Drawing::Size(45, 45);
			this->A3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A3->TabIndex = 448;
			this->A3->TabStop = false;
			this->A3->Visible = false;
			// 
			// A2
			// 
			this->A2->AccessibleName = L"A2";
			this->A2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A2.Image")));
			this->A2->Location = System::Drawing::Point(45, 373);
			this->A2->Margin = System::Windows::Forms::Padding(1);
			this->A2->MaximumSize = System::Drawing::Size(45, 45);
			this->A2->MinimumSize = System::Drawing::Size(20, 20);
			this->A2->Name = L"A2";
			this->A2->Size = System::Drawing::Size(45, 45);
			this->A2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A2->TabIndex = 447;
			this->A2->TabStop = false;
			this->A2->Visible = false;
			// 
			// A1
			// 
			this->A1->AccessibleName = L"A1";
			this->A1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->A1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->A1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"A1.Image")));
			this->A1->Location = System::Drawing::Point(46, 428);
			this->A1->Margin = System::Windows::Forms::Padding(1);
			this->A1->MaximumSize = System::Drawing::Size(45, 45);
			this->A1->MinimumSize = System::Drawing::Size(20, 20);
			this->A1->Name = L"A1";
			this->A1->Size = System::Drawing::Size(45, 45);
			this->A1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->A1->TabIndex = 446;
			this->A1->TabStop = false;
			this->A1->Visible = false;
			// 
			// B8
			// 
			this->B8->AccessibleName = L"B8";
			this->B8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B8.Image")));
			this->B8->Location = System::Drawing::Point(106, 44);
			this->B8->Margin = System::Windows::Forms::Padding(1);
			this->B8->MaximumSize = System::Drawing::Size(45, 45);
			this->B8->MinimumSize = System::Drawing::Size(20, 20);
			this->B8->Name = L"B8";
			this->B8->Size = System::Drawing::Size(45, 45);
			this->B8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B8->TabIndex = 461;
			this->B8->TabStop = false;
			this->B8->Visible = false;
			// 
			// B7
			// 
			this->B7->AccessibleName = L"B7";
			this->B7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B7.Image")));
			this->B7->Location = System::Drawing::Point(106, 101);
			this->B7->Margin = System::Windows::Forms::Padding(1);
			this->B7->MaximumSize = System::Drawing::Size(45, 45);
			this->B7->MinimumSize = System::Drawing::Size(20, 20);
			this->B7->Name = L"B7";
			this->B7->Size = System::Drawing::Size(45, 45);
			this->B7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B7->TabIndex = 460;
			this->B7->TabStop = false;
			this->B7->Visible = false;
			// 
			// B6
			// 
			this->B6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B6.Image")));
			this->B6->Location = System::Drawing::Point(105, 155);
			this->B6->Margin = System::Windows::Forms::Padding(1);
			this->B6->MaximumSize = System::Drawing::Size(45, 45);
			this->B6->MinimumSize = System::Drawing::Size(20, 20);
			this->B6->Name = L"B6";
			this->B6->Size = System::Drawing::Size(45, 45);
			this->B6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B6->TabIndex = 459;
			this->B6->TabStop = false;
			this->B6->Visible = false;
			// 
			// B5
			// 
			this->B5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B5.Image")));
			this->B5->Location = System::Drawing::Point(106, 212);
			this->B5->Margin = System::Windows::Forms::Padding(1);
			this->B5->MaximumSize = System::Drawing::Size(45, 45);
			this->B5->MinimumSize = System::Drawing::Size(20, 20);
			this->B5->Name = L"B5";
			this->B5->Size = System::Drawing::Size(45, 45);
			this->B5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B5->TabIndex = 458;
			this->B5->TabStop = false;
			this->B5->Visible = false;
			// 
			// B4
			// 
			this->B4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B4.Image")));
			this->B4->Location = System::Drawing::Point(106, 260);
			this->B4->Margin = System::Windows::Forms::Padding(1);
			this->B4->MaximumSize = System::Drawing::Size(45, 45);
			this->B4->MinimumSize = System::Drawing::Size(20, 20);
			this->B4->Name = L"B4";
			this->B4->Size = System::Drawing::Size(45, 45);
			this->B4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B4->TabIndex = 457;
			this->B4->TabStop = false;
			this->B4->Visible = false;
			// 
			// B3
			// 
			this->B3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B3.Image")));
			this->B3->Location = System::Drawing::Point(106, 316);
			this->B3->Margin = System::Windows::Forms::Padding(1);
			this->B3->MaximumSize = System::Drawing::Size(45, 45);
			this->B3->MinimumSize = System::Drawing::Size(20, 20);
			this->B3->Name = L"B3";
			this->B3->Size = System::Drawing::Size(45, 45);
			this->B3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B3->TabIndex = 456;
			this->B3->TabStop = false;
			this->B3->Visible = false;
			// 
			// B2
			// 
			this->B2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B2.Image")));
			this->B2->Location = System::Drawing::Point(105, 373);
			this->B2->Margin = System::Windows::Forms::Padding(1);
			this->B2->MaximumSize = System::Drawing::Size(45, 45);
			this->B2->MinimumSize = System::Drawing::Size(20, 20);
			this->B2->Name = L"B2";
			this->B2->Size = System::Drawing::Size(45, 45);
			this->B2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B2->TabIndex = 455;
			this->B2->TabStop = false;
			this->B2->Visible = false;
			// 
			// B1
			// 
			this->B1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->B1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->B1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"B1.Image")));
			this->B1->Location = System::Drawing::Point(105, 428);
			this->B1->Margin = System::Windows::Forms::Padding(1);
			this->B1->MaximumSize = System::Drawing::Size(45, 45);
			this->B1->MinimumSize = System::Drawing::Size(20, 20);
			this->B1->Name = L"B1";
			this->B1->Size = System::Drawing::Size(45, 45);
			this->B1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->B1->TabIndex = 454;
			this->B1->TabStop = false;
			this->B1->Visible = false;
			// 
			// C8
			// 
			this->C8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C8.Image")));
			this->C8->Location = System::Drawing::Point(157, 44);
			this->C8->Margin = System::Windows::Forms::Padding(1);
			this->C8->MaximumSize = System::Drawing::Size(45, 45);
			this->C8->MinimumSize = System::Drawing::Size(20, 20);
			this->C8->Name = L"C8";
			this->C8->Size = System::Drawing::Size(45, 45);
			this->C8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C8->TabIndex = 469;
			this->C8->TabStop = false;
			this->C8->Visible = false;
			// 
			// C7
			// 
			this->C7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C7.Image")));
			this->C7->Location = System::Drawing::Point(157, 101);
			this->C7->Margin = System::Windows::Forms::Padding(1);
			this->C7->MaximumSize = System::Drawing::Size(45, 45);
			this->C7->MinimumSize = System::Drawing::Size(20, 20);
			this->C7->Name = L"C7";
			this->C7->Size = System::Drawing::Size(45, 45);
			this->C7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C7->TabIndex = 468;
			this->C7->TabStop = false;
			this->C7->Visible = false;
			// 
			// C6
			// 
			this->C6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C6.Image")));
			this->C6->Location = System::Drawing::Point(156, 155);
			this->C6->Margin = System::Windows::Forms::Padding(1);
			this->C6->MaximumSize = System::Drawing::Size(45, 45);
			this->C6->MinimumSize = System::Drawing::Size(20, 20);
			this->C6->Name = L"C6";
			this->C6->Size = System::Drawing::Size(45, 45);
			this->C6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C6->TabIndex = 467;
			this->C6->TabStop = false;
			this->C6->Visible = false;
			// 
			// C5
			// 
			this->C5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C5.Image")));
			this->C5->Location = System::Drawing::Point(157, 212);
			this->C5->Margin = System::Windows::Forms::Padding(1);
			this->C5->MaximumSize = System::Drawing::Size(45, 45);
			this->C5->MinimumSize = System::Drawing::Size(20, 20);
			this->C5->Name = L"C5";
			this->C5->Size = System::Drawing::Size(45, 45);
			this->C5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C5->TabIndex = 466;
			this->C5->TabStop = false;
			this->C5->Visible = false;
			// 
			// C4
			// 
			this->C4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C4.Image")));
			this->C4->Location = System::Drawing::Point(157, 260);
			this->C4->Margin = System::Windows::Forms::Padding(1);
			this->C4->MaximumSize = System::Drawing::Size(45, 45);
			this->C4->MinimumSize = System::Drawing::Size(20, 20);
			this->C4->Name = L"C4";
			this->C4->Size = System::Drawing::Size(45, 45);
			this->C4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C4->TabIndex = 465;
			this->C4->TabStop = false;
			this->C4->Visible = false;
			// 
			// C3
			// 
			this->C3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C3.Image")));
			this->C3->Location = System::Drawing::Point(157, 316);
			this->C3->Margin = System::Windows::Forms::Padding(1);
			this->C3->MaximumSize = System::Drawing::Size(45, 45);
			this->C3->MinimumSize = System::Drawing::Size(20, 20);
			this->C3->Name = L"C3";
			this->C3->Size = System::Drawing::Size(45, 45);
			this->C3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C3->TabIndex = 464;
			this->C3->TabStop = false;
			this->C3->Visible = false;
			// 
			// C2
			// 
			this->C2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C2.Image")));
			this->C2->Location = System::Drawing::Point(156, 373);
			this->C2->Margin = System::Windows::Forms::Padding(1);
			this->C2->MaximumSize = System::Drawing::Size(45, 45);
			this->C2->MinimumSize = System::Drawing::Size(20, 20);
			this->C2->Name = L"C2";
			this->C2->Size = System::Drawing::Size(45, 45);
			this->C2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C2->TabIndex = 463;
			this->C2->TabStop = false;
			this->C2->Visible = false;
			// 
			// C1
			// 
			this->C1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->C1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->C1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"C1.Image")));
			this->C1->Location = System::Drawing::Point(157, 428);
			this->C1->Margin = System::Windows::Forms::Padding(1);
			this->C1->MaximumSize = System::Drawing::Size(45, 45);
			this->C1->MinimumSize = System::Drawing::Size(20, 20);
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(45, 45);
			this->C1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->C1->TabIndex = 462;
			this->C1->TabStop = false;
			this->C1->Visible = false;
			// 
			// D8
			// 
			this->D8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D8.Image")));
			this->D8->Location = System::Drawing::Point(211, 44);
			this->D8->Margin = System::Windows::Forms::Padding(1);
			this->D8->MaximumSize = System::Drawing::Size(45, 45);
			this->D8->MinimumSize = System::Drawing::Size(20, 20);
			this->D8->Name = L"D8";
			this->D8->Size = System::Drawing::Size(45, 45);
			this->D8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D8->TabIndex = 477;
			this->D8->TabStop = false;
			this->D8->Visible = false;
			// 
			// D7
			// 
			this->D7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D7.Image")));
			this->D7->Location = System::Drawing::Point(211, 101);
			this->D7->Margin = System::Windows::Forms::Padding(1);
			this->D7->MaximumSize = System::Drawing::Size(45, 45);
			this->D7->MinimumSize = System::Drawing::Size(20, 20);
			this->D7->Name = L"D7";
			this->D7->Size = System::Drawing::Size(45, 45);
			this->D7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D7->TabIndex = 476;
			this->D7->TabStop = false;
			this->D7->Visible = false;
			// 
			// D6
			// 
			this->D6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D6.Image")));
			this->D6->Location = System::Drawing::Point(210, 155);
			this->D6->Margin = System::Windows::Forms::Padding(1);
			this->D6->MaximumSize = System::Drawing::Size(45, 45);
			this->D6->MinimumSize = System::Drawing::Size(20, 20);
			this->D6->Name = L"D6";
			this->D6->Size = System::Drawing::Size(45, 45);
			this->D6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D6->TabIndex = 475;
			this->D6->TabStop = false;
			this->D6->Visible = false;
			// 
			// D5
			// 
			this->D5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D5.Image")));
			this->D5->Location = System::Drawing::Point(211, 212);
			this->D5->Margin = System::Windows::Forms::Padding(1);
			this->D5->MaximumSize = System::Drawing::Size(45, 45);
			this->D5->MinimumSize = System::Drawing::Size(20, 20);
			this->D5->Name = L"D5";
			this->D5->Size = System::Drawing::Size(45, 45);
			this->D5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D5->TabIndex = 474;
			this->D5->TabStop = false;
			this->D5->Visible = false;
			// 
			// D4
			// 
			this->D4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D4.Image")));
			this->D4->Location = System::Drawing::Point(211, 260);
			this->D4->Margin = System::Windows::Forms::Padding(1);
			this->D4->MaximumSize = System::Drawing::Size(45, 45);
			this->D4->MinimumSize = System::Drawing::Size(20, 20);
			this->D4->Name = L"D4";
			this->D4->Size = System::Drawing::Size(45, 45);
			this->D4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D4->TabIndex = 473;
			this->D4->TabStop = false;
			this->D4->Visible = false;
			// 
			// D3
			// 
			this->D3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D3.Image")));
			this->D3->Location = System::Drawing::Point(211, 316);
			this->D3->Margin = System::Windows::Forms::Padding(1);
			this->D3->MaximumSize = System::Drawing::Size(45, 45);
			this->D3->MinimumSize = System::Drawing::Size(20, 20);
			this->D3->Name = L"D3";
			this->D3->Size = System::Drawing::Size(45, 45);
			this->D3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D3->TabIndex = 472;
			this->D3->TabStop = false;
			this->D3->Visible = false;
			// 
			// D2
			// 
			this->D2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D2.Image")));
			this->D2->Location = System::Drawing::Point(210, 373);
			this->D2->Margin = System::Windows::Forms::Padding(1);
			this->D2->MaximumSize = System::Drawing::Size(45, 45);
			this->D2->MinimumSize = System::Drawing::Size(20, 20);
			this->D2->Name = L"D2";
			this->D2->Size = System::Drawing::Size(45, 45);
			this->D2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D2->TabIndex = 471;
			this->D2->TabStop = false;
			this->D2->Visible = false;
			// 
			// D1
			// 
			this->D1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->D1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->D1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"D1.Image")));
			this->D1->Location = System::Drawing::Point(211, 428);
			this->D1->Margin = System::Windows::Forms::Padding(1);
			this->D1->MaximumSize = System::Drawing::Size(45, 45);
			this->D1->MinimumSize = System::Drawing::Size(20, 20);
			this->D1->Name = L"D1";
			this->D1->Size = System::Drawing::Size(45, 45);
			this->D1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->D1->TabIndex = 470;
			this->D1->TabStop = false;
			this->D1->Visible = false;
			// 
			// E8
			// 
			this->E8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E8.Image")));
			this->E8->Location = System::Drawing::Point(264, 44);
			this->E8->Margin = System::Windows::Forms::Padding(1);
			this->E8->MaximumSize = System::Drawing::Size(45, 45);
			this->E8->MinimumSize = System::Drawing::Size(20, 20);
			this->E8->Name = L"E8";
			this->E8->Size = System::Drawing::Size(45, 45);
			this->E8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E8->TabIndex = 485;
			this->E8->TabStop = false;
			this->E8->Visible = false;
			// 
			// E7
			// 
			this->E7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E7.Image")));
			this->E7->Location = System::Drawing::Point(264, 101);
			this->E7->Margin = System::Windows::Forms::Padding(1);
			this->E7->MaximumSize = System::Drawing::Size(45, 45);
			this->E7->MinimumSize = System::Drawing::Size(20, 20);
			this->E7->Name = L"E7";
			this->E7->Size = System::Drawing::Size(45, 45);
			this->E7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E7->TabIndex = 484;
			this->E7->TabStop = false;
			this->E7->Visible = false;
			// 
			// E6
			// 
			this->E6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E6.Image")));
			this->E6->Location = System::Drawing::Point(263, 155);
			this->E6->Margin = System::Windows::Forms::Padding(1);
			this->E6->MaximumSize = System::Drawing::Size(45, 45);
			this->E6->MinimumSize = System::Drawing::Size(20, 20);
			this->E6->Name = L"E6";
			this->E6->Size = System::Drawing::Size(45, 45);
			this->E6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E6->TabIndex = 483;
			this->E6->TabStop = false;
			this->E6->Visible = false;
			// 
			// E5
			// 
			this->E5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E5.Image")));
			this->E5->Location = System::Drawing::Point(264, 212);
			this->E5->Margin = System::Windows::Forms::Padding(1);
			this->E5->MaximumSize = System::Drawing::Size(45, 45);
			this->E5->MinimumSize = System::Drawing::Size(20, 20);
			this->E5->Name = L"E5";
			this->E5->Size = System::Drawing::Size(45, 45);
			this->E5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E5->TabIndex = 482;
			this->E5->TabStop = false;
			this->E5->Visible = false;
			// 
			// E4
			// 
			this->E4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E4.Image")));
			this->E4->Location = System::Drawing::Point(264, 260);
			this->E4->Margin = System::Windows::Forms::Padding(1);
			this->E4->MaximumSize = System::Drawing::Size(45, 45);
			this->E4->MinimumSize = System::Drawing::Size(20, 20);
			this->E4->Name = L"E4";
			this->E4->Size = System::Drawing::Size(45, 45);
			this->E4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E4->TabIndex = 481;
			this->E4->TabStop = false;
			this->E4->Visible = false;
			// 
			// E3
			// 
			this->E3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E3.Image")));
			this->E3->Location = System::Drawing::Point(264, 316);
			this->E3->Margin = System::Windows::Forms::Padding(1);
			this->E3->MaximumSize = System::Drawing::Size(45, 45);
			this->E3->MinimumSize = System::Drawing::Size(20, 20);
			this->E3->Name = L"E3";
			this->E3->Size = System::Drawing::Size(45, 45);
			this->E3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E3->TabIndex = 480;
			this->E3->TabStop = false;
			this->E3->Visible = false;
			// 
			// E2
			// 
			this->E2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E2.Image")));
			this->E2->Location = System::Drawing::Point(263, 373);
			this->E2->Margin = System::Windows::Forms::Padding(1);
			this->E2->MaximumSize = System::Drawing::Size(45, 45);
			this->E2->MinimumSize = System::Drawing::Size(20, 20);
			this->E2->Name = L"E2";
			this->E2->Size = System::Drawing::Size(45, 45);
			this->E2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E2->TabIndex = 479;
			this->E2->TabStop = false;
			this->E2->Visible = false;
			// 
			// E1
			// 
			this->E1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->E1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->E1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"E1.Image")));
			this->E1->Location = System::Drawing::Point(264, 428);
			this->E1->Margin = System::Windows::Forms::Padding(1);
			this->E1->MaximumSize = System::Drawing::Size(45, 45);
			this->E1->MinimumSize = System::Drawing::Size(20, 20);
			this->E1->Name = L"E1";
			this->E1->Size = System::Drawing::Size(45, 45);
			this->E1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->E1->TabIndex = 478;
			this->E1->TabStop = false;
			this->E1->Visible = false;
			// 
			// F8
			// 
			this->F8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F8.Image")));
			this->F8->Location = System::Drawing::Point(317, 44);
			this->F8->Margin = System::Windows::Forms::Padding(1);
			this->F8->MaximumSize = System::Drawing::Size(45, 45);
			this->F8->MinimumSize = System::Drawing::Size(20, 20);
			this->F8->Name = L"F8";
			this->F8->Size = System::Drawing::Size(45, 45);
			this->F8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F8->TabIndex = 493;
			this->F8->TabStop = false;
			this->F8->Visible = false;
			// 
			// F7
			// 
			this->F7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F7.Image")));
			this->F7->Location = System::Drawing::Point(317, 101);
			this->F7->Margin = System::Windows::Forms::Padding(1);
			this->F7->MaximumSize = System::Drawing::Size(45, 45);
			this->F7->MinimumSize = System::Drawing::Size(20, 20);
			this->F7->Name = L"F7";
			this->F7->Size = System::Drawing::Size(45, 45);
			this->F7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F7->TabIndex = 492;
			this->F7->TabStop = false;
			this->F7->Visible = false;
			// 
			// F6
			// 
			this->F6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F6.Image")));
			this->F6->Location = System::Drawing::Point(316, 155);
			this->F6->Margin = System::Windows::Forms::Padding(1);
			this->F6->MaximumSize = System::Drawing::Size(45, 45);
			this->F6->MinimumSize = System::Drawing::Size(20, 20);
			this->F6->Name = L"F6";
			this->F6->Size = System::Drawing::Size(45, 45);
			this->F6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F6->TabIndex = 491;
			this->F6->TabStop = false;
			this->F6->Visible = false;
			// 
			// F5
			// 
			this->F5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F5.Image")));
			this->F5->Location = System::Drawing::Point(317, 212);
			this->F5->Margin = System::Windows::Forms::Padding(1);
			this->F5->MaximumSize = System::Drawing::Size(45, 45);
			this->F5->MinimumSize = System::Drawing::Size(20, 20);
			this->F5->Name = L"F5";
			this->F5->Size = System::Drawing::Size(45, 45);
			this->F5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F5->TabIndex = 490;
			this->F5->TabStop = false;
			this->F5->Visible = false;
			// 
			// F4
			// 
			this->F4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F4.Image")));
			this->F4->Location = System::Drawing::Point(317, 260);
			this->F4->Margin = System::Windows::Forms::Padding(1);
			this->F4->MaximumSize = System::Drawing::Size(45, 45);
			this->F4->MinimumSize = System::Drawing::Size(20, 20);
			this->F4->Name = L"F4";
			this->F4->Size = System::Drawing::Size(45, 45);
			this->F4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F4->TabIndex = 489;
			this->F4->TabStop = false;
			this->F4->Visible = false;
			// 
			// F3
			// 
			this->F3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F3.Image")));
			this->F3->Location = System::Drawing::Point(317, 316);
			this->F3->Margin = System::Windows::Forms::Padding(1);
			this->F3->MaximumSize = System::Drawing::Size(45, 45);
			this->F3->MinimumSize = System::Drawing::Size(20, 20);
			this->F3->Name = L"F3";
			this->F3->Size = System::Drawing::Size(45, 45);
			this->F3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F3->TabIndex = 488;
			this->F3->TabStop = false;
			this->F3->Visible = false;
			// 
			// F2
			// 
			this->F2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F2.Image")));
			this->F2->Location = System::Drawing::Point(316, 373);
			this->F2->Margin = System::Windows::Forms::Padding(1);
			this->F2->MaximumSize = System::Drawing::Size(45, 45);
			this->F2->MinimumSize = System::Drawing::Size(20, 20);
			this->F2->Name = L"F2";
			this->F2->Size = System::Drawing::Size(45, 45);
			this->F2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F2->TabIndex = 487;
			this->F2->TabStop = false;
			this->F2->Visible = false;
			// 
			// F1
			// 
			this->F1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->F1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->F1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"F1.Image")));
			this->F1->Location = System::Drawing::Point(317, 428);
			this->F1->Margin = System::Windows::Forms::Padding(1);
			this->F1->MaximumSize = System::Drawing::Size(45, 45);
			this->F1->MinimumSize = System::Drawing::Size(20, 20);
			this->F1->Name = L"F1";
			this->F1->Size = System::Drawing::Size(45, 45);
			this->F1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->F1->TabIndex = 486;
			this->F1->TabStop = false;
			this->F1->Visible = false;
			// 
			// G8
			// 
			this->G8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G8.Image")));
			this->G8->Location = System::Drawing::Point(372, 44);
			this->G8->Margin = System::Windows::Forms::Padding(1);
			this->G8->MaximumSize = System::Drawing::Size(45, 45);
			this->G8->MinimumSize = System::Drawing::Size(20, 20);
			this->G8->Name = L"G8";
			this->G8->Size = System::Drawing::Size(45, 45);
			this->G8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G8->TabIndex = 501;
			this->G8->TabStop = false;
			this->G8->Visible = false;
			// 
			// G7
			// 
			this->G7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G7.Image")));
			this->G7->Location = System::Drawing::Point(372, 101);
			this->G7->Margin = System::Windows::Forms::Padding(1);
			this->G7->MaximumSize = System::Drawing::Size(45, 45);
			this->G7->MinimumSize = System::Drawing::Size(20, 20);
			this->G7->Name = L"G7";
			this->G7->Size = System::Drawing::Size(45, 45);
			this->G7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G7->TabIndex = 500;
			this->G7->TabStop = false;
			this->G7->Visible = false;
			// 
			// G6
			// 
			this->G6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G6.Image")));
			this->G6->Location = System::Drawing::Point(371, 155);
			this->G6->Margin = System::Windows::Forms::Padding(1);
			this->G6->MaximumSize = System::Drawing::Size(45, 45);
			this->G6->MinimumSize = System::Drawing::Size(20, 20);
			this->G6->Name = L"G6";
			this->G6->Size = System::Drawing::Size(45, 45);
			this->G6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G6->TabIndex = 499;
			this->G6->TabStop = false;
			this->G6->Visible = false;
			// 
			// G5
			// 
			this->G5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G5.Image")));
			this->G5->Location = System::Drawing::Point(372, 212);
			this->G5->Margin = System::Windows::Forms::Padding(1);
			this->G5->MaximumSize = System::Drawing::Size(45, 45);
			this->G5->MinimumSize = System::Drawing::Size(20, 20);
			this->G5->Name = L"G5";
			this->G5->Size = System::Drawing::Size(45, 45);
			this->G5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G5->TabIndex = 498;
			this->G5->TabStop = false;
			this->G5->Visible = false;
			// 
			// G4
			// 
			this->G4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G4.Image")));
			this->G4->Location = System::Drawing::Point(372, 260);
			this->G4->Margin = System::Windows::Forms::Padding(1);
			this->G4->MaximumSize = System::Drawing::Size(45, 45);
			this->G4->MinimumSize = System::Drawing::Size(20, 20);
			this->G4->Name = L"G4";
			this->G4->Size = System::Drawing::Size(45, 45);
			this->G4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G4->TabIndex = 497;
			this->G4->TabStop = false;
			this->G4->Visible = false;
			// 
			// G3
			// 
			this->G3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G3.Image")));
			this->G3->Location = System::Drawing::Point(372, 316);
			this->G3->Margin = System::Windows::Forms::Padding(1);
			this->G3->MaximumSize = System::Drawing::Size(45, 45);
			this->G3->MinimumSize = System::Drawing::Size(20, 20);
			this->G3->Name = L"G3";
			this->G3->Size = System::Drawing::Size(45, 45);
			this->G3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G3->TabIndex = 496;
			this->G3->TabStop = false;
			this->G3->Visible = false;
			// 
			// G2
			// 
			this->G2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G2.Image")));
			this->G2->Location = System::Drawing::Point(371, 373);
			this->G2->Margin = System::Windows::Forms::Padding(1);
			this->G2->MaximumSize = System::Drawing::Size(45, 45);
			this->G2->MinimumSize = System::Drawing::Size(20, 20);
			this->G2->Name = L"G2";
			this->G2->Size = System::Drawing::Size(45, 45);
			this->G2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G2->TabIndex = 495;
			this->G2->TabStop = false;
			this->G2->Visible = false;
			// 
			// G1
			// 
			this->G1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->G1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->G1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"G1.Image")));
			this->G1->Location = System::Drawing::Point(372, 428);
			this->G1->Margin = System::Windows::Forms::Padding(1);
			this->G1->MaximumSize = System::Drawing::Size(45, 45);
			this->G1->MinimumSize = System::Drawing::Size(20, 20);
			this->G1->Name = L"G1";
			this->G1->Size = System::Drawing::Size(45, 45);
			this->G1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->G1->TabIndex = 494;
			this->G1->TabStop = false;
			this->G1->Visible = false;
			// 
			// H8
			// 
			this->H8->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H8.Image")));
			this->H8->Location = System::Drawing::Point(429, 44);
			this->H8->Margin = System::Windows::Forms::Padding(1);
			this->H8->MaximumSize = System::Drawing::Size(45, 45);
			this->H8->MinimumSize = System::Drawing::Size(20, 20);
			this->H8->Name = L"H8";
			this->H8->Size = System::Drawing::Size(45, 45);
			this->H8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H8->TabIndex = 509;
			this->H8->TabStop = false;
			this->H8->Visible = false;
			// 
			// H7
			// 
			this->H7->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H7.Image")));
			this->H7->Location = System::Drawing::Point(430, 101);
			this->H7->Margin = System::Windows::Forms::Padding(1);
			this->H7->MaximumSize = System::Drawing::Size(45, 45);
			this->H7->MinimumSize = System::Drawing::Size(20, 20);
			this->H7->Name = L"H7";
			this->H7->Size = System::Drawing::Size(45, 45);
			this->H7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H7->TabIndex = 508;
			this->H7->TabStop = false;
			this->H7->Visible = false;
			// 
			// H6
			// 
			this->H6->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H6.Image")));
			this->H6->Location = System::Drawing::Point(429, 155);
			this->H6->Margin = System::Windows::Forms::Padding(1);
			this->H6->MaximumSize = System::Drawing::Size(45, 45);
			this->H6->MinimumSize = System::Drawing::Size(20, 20);
			this->H6->Name = L"H6";
			this->H6->Size = System::Drawing::Size(45, 45);
			this->H6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H6->TabIndex = 507;
			this->H6->TabStop = false;
			this->H6->Visible = false;
			// 
			// H5
			// 
			this->H5->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H5.Image")));
			this->H5->Location = System::Drawing::Point(430, 212);
			this->H5->Margin = System::Windows::Forms::Padding(1);
			this->H5->MaximumSize = System::Drawing::Size(45, 45);
			this->H5->MinimumSize = System::Drawing::Size(20, 20);
			this->H5->Name = L"H5";
			this->H5->Size = System::Drawing::Size(45, 45);
			this->H5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H5->TabIndex = 506;
			this->H5->TabStop = false;
			this->H5->Visible = false;
			// 
			// H4
			// 
			this->H4->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H4.Image")));
			this->H4->Location = System::Drawing::Point(430, 260);
			this->H4->Margin = System::Windows::Forms::Padding(1);
			this->H4->MaximumSize = System::Drawing::Size(45, 45);
			this->H4->MinimumSize = System::Drawing::Size(20, 20);
			this->H4->Name = L"H4";
			this->H4->Size = System::Drawing::Size(45, 45);
			this->H4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H4->TabIndex = 505;
			this->H4->TabStop = false;
			this->H4->Visible = false;
			// 
			// H3
			// 
			this->H3->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H3.Image")));
			this->H3->Location = System::Drawing::Point(430, 316);
			this->H3->Margin = System::Windows::Forms::Padding(1);
			this->H3->MaximumSize = System::Drawing::Size(45, 45);
			this->H3->MinimumSize = System::Drawing::Size(20, 20);
			this->H3->Name = L"H3";
			this->H3->Size = System::Drawing::Size(45, 45);
			this->H3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H3->TabIndex = 504;
			this->H3->TabStop = false;
			this->H3->Visible = false;
			// 
			// H2
			// 
			this->H2->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H2.Image")));
			this->H2->Location = System::Drawing::Point(429, 373);
			this->H2->Margin = System::Windows::Forms::Padding(1);
			this->H2->MaximumSize = System::Drawing::Size(45, 45);
			this->H2->MinimumSize = System::Drawing::Size(20, 20);
			this->H2->Name = L"H2";
			this->H2->Size = System::Drawing::Size(45, 45);
			this->H2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H2->TabIndex = 503;
			this->H2->TabStop = false;
			this->H2->Visible = false;
			// 
			// H1
			// 
			this->H1->AccessibleRole = System::Windows::Forms::AccessibleRole::Animation;
			this->H1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->H1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"H1.Image")));
			this->H1->Location = System::Drawing::Point(430, 428);
			this->H1->Margin = System::Windows::Forms::Padding(1);
			this->H1->MaximumSize = System::Drawing::Size(45, 45);
			this->H1->MinimumSize = System::Drawing::Size(20, 20);
			this->H1->Name = L"H1";
			this->H1->Size = System::Drawing::Size(45, 45);
			this->H1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->H1->TabIndex = 502;
			this->H1->TabStop = false;
			this->H1->Visible = false;
			// 
			// pictureBoxChessboard
			// 
			this->pictureBoxChessboard->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBoxChessboard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxChessboard.Image")));
			this->pictureBoxChessboard->Location = System::Drawing::Point(10, 8);
			this->pictureBoxChessboard->Margin = System::Windows::Forms::Padding(0);
			this->pictureBoxChessboard->MaximumSize = System::Drawing::Size(500, 500);
			this->pictureBoxChessboard->MinimumSize = System::Drawing::Size(480, 480);
			this->pictureBoxChessboard->Name = L"pictureBoxChessboard";
			this->pictureBoxChessboard->Size = System::Drawing::Size(500, 500);
			this->pictureBoxChessboard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxChessboard->TabIndex = 445;
			this->pictureBoxChessboard->TabStop = false;
			// 
			// labelPlayerValue
			// 
			this->labelPlayerValue->AutoSize = true;
			this->labelPlayerValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelPlayerValue->Location = System::Drawing::Point(651, 9);
			this->labelPlayerValue->Name = L"labelPlayerValue";
			this->labelPlayerValue->Size = System::Drawing::Size(61, 24);
			this->labelPlayerValue->TabIndex = 461;
			this->labelPlayerValue->Text = L"Name";
			// 
			// labelPlayer
			// 
			this->labelPlayer->AutoSize = true;
			this->labelPlayer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelPlayer->Location = System::Drawing::Point(552, 9);
			this->labelPlayer->Name = L"labelPlayer";
			this->labelPlayer->Size = System::Drawing::Size(67, 24);
			this->labelPlayer->TabIndex = 460;
			this->labelPlayer->Text = L"Player:";
			// 
			// timerGame
			// 
			this->timerGame->Interval = 1000;
			this->timerGame->Tick += gcnew System::EventHandler(this, &mcmah113Chessboard::timerGame_Tick);
			// 
			// mcmah113Chessboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 518);
			this->Controls->Add(this->labelPlayerValue);
			this->Controls->Add(this->labelPlayer);
			this->Controls->Add(this->panelChessboard);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelInstructions);
			this->Controls->Add(this->labelScoreValue);
			this->Controls->Add(this->labelScoreText);
			this->Controls->Add(this->labelTimeValue);
			this->Controls->Add(this->labelTimeText);
			this->Controls->Add(this->pictureBoxGameResponse);
			this->Controls->Add(this->textBoxQuadrant);
			this->Controls->Add(this->labelInputResponse);
			this->Controls->Add(this->buttonEnterQueen);
			this->Controls->Add(this->buttonRemoveQueen);
			this->Controls->Add(this->buttonNewGame);
			this->Controls->Add(this->buttonClose);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(800, 557);
			this->MinimumSize = System::Drawing::Size(800, 557);
			this->Name = L"mcmah113Chessboard";
			this->Text = L"mcmah113Chessboard";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGameResponse))->EndInit();
			this->panelChessboard->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->D1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->E1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->F1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->G1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->H1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxChessboard))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//component events
		private: System::Void buttonClose_Click(System::Object^  sender, System::EventArgs^  e) {
			int score = Convert::ToInt32(labelScoreValue->Text);

			if (score > 0) {
				timerGame->Stop();
				String^ leavingMessge = "Too bad you couldn't complete the game." + "\n" + "Number of Queens: " + numQueens + "\n" + "Score: " + score + "\n" + "Time: " + labelTimeValue->Text;
				MessageBox::Show(leavingMessge, "Score has been Recorded!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				recordPlayerScore(labelPlayerValue->Text,labelScoreValue->Text,labelTimeValue->Text);
			}

			this->Close();
		}
		private: System::Void buttonEnterQueen_Click(System::Object^  sender, System::EventArgs^  e) {
			addQueen(textBoxQuadrant->Text);
			textBoxQuadrant->Text = "";
		}
		private: System::Void buttonRemoveQueen_Click(System::Object^  sender, System::EventArgs^  e) {
			removeQueen(textBoxQuadrant->Text);
			textBoxQuadrant->Text = "";
		}
		private: System::Void buttonNewGame_Click(System::Object^  sender, System::EventArgs^  e) {
			newGame();
		}	
		private: System::Void timerGame_Tick(System::Object^  sender, System::EventArgs^  e) {
			time++;
			labelTimeValue->Text = "" + time;
		}

		//reset the list containing all of the board quadrants to false, true meaning theirs a queen their
		private: System::Void newGame() {
			int score = Convert::ToInt32(labelScoreValue->Text);

			if (score > 0) {
				timerGame->Stop();
				String^ leavingMessge = "Too bad you couldn't complete the game." + "\n" + "Number of Queens: " + numQueens + "\n" +"Score: " + score + "\n" + "Time: " + labelTimeValue->Text;
				MessageBox::Show(leavingMessge, "Score has been Recorded!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				recordPlayerScore(labelPlayerValue->Text, labelScoreValue->Text, labelTimeValue->Text);
			}

			//System::Diagnostics::Debug::WriteLine("NEW GAME \n\n");

			for (int i = 0; i < queenLocations->Count; i++) {
				//System::Diagnostics::Debug::WriteLine("Key: " + keysList[i] + " = " + queenLocations[keysList[i]]);
				queenLocations[keysList[i]] = false;
				PictureBox^ quadrantImage = (PictureBox^)panelChessboard->Controls->Find(keysList[i], true)[0];
				quadrantImage->Hide();
			}

			numQueens = 0;
			labelScoreValue->Text = "0";
			labelTimeValue->Text = "0";
			buttonEnterQueen->Enabled = false;
			buttonRemoveQueen->Enabled = false;
			textBoxQuadrant->Enabled = false;

			mcmah113PlayerNameDialog^ playerNameDialog = gcnew mcmah113PlayerNameDialog;
			playerNameDialog->ShowDialog();
			labelPlayerValue->Text = playerNameDialog->textBoxPlayerName->Text;

			if (!String::IsNullOrEmpty(labelPlayerValue->Text) && !String::IsNullOrWhiteSpace(labelPlayerValue->Text)) {
				//only enable gameplay when a valid name is typed 
				time = 0;
				timerGame->Enabled = true;
				buttonEnterQueen->Enabled = true;
				buttonRemoveQueen->Enabled = true;
				textBoxQuadrant->Enabled = true;
			}
		}

		private: System::Void addQueen(String^ quadrant) {
			try {
				//see if the quadrant the user typed in is valid by attempting to look it up in the list
				if (queenLocations[quadrant] == true) {
					//this quadrant already has a queen, invalid input
					labelInputResponse->Text = "Queen already at " + quadrant;
					labelInputResponse->ForeColor = Color::Red;
				}
				else {
					//this quadrant is free, place the queen by showing the image
					numQueens++;

					labelInputResponse->Text = "Queen placed at " + quadrant;
					labelInputResponse->ForeColor = Color::Green;

					queenLocations[quadrant] = true;
					PictureBox^ quadrantImage = (PictureBox^) panelChessboard->Controls->Find(quadrant, true)[0];
					quadrantImage->Show();
					
					int score = Convert::ToInt32(labelScoreValue->Text);

					bool queensSafeFlag;
					int queenIndex;

					for (int index = 0; index < numQueens; index++) {

						//this loops through the chessboard looking for queens and returns their index
						//will only return the current queens (index) location
						queenIndex = queensQuadrant(index);
						
						//recursive function that will check all danger zones of that queens location 
						//and only return true when no queens are found
						queensSafeFlag = allQueensSafe(queenIndex, queenIndex, false, false, false, false, false);

						if (queensSafeFlag == false) {
							//a queen was found at some point during the checks, bad queen placement
							break;
						}
					}

					if (queensSafeFlag == true) {
						//user placed the queen in a safe location, give them 100 points
						score += 100;
						labelScoreValue->Text = "" + score;

						pictureBoxGameResponse->ImageLocation = "Smile.png";

						SoundPlayer^ soundEffect = gcnew SoundPlayer("C:\\windows\\media\\tada.wav");
						soundEffect->Play();

						if (numQueens == 8) {
							timerGame->Stop();
							//user has placed all 8 queens succesfully, end game
							String^ endGameString = "You were able to place all 8 Queens succesfully!" + "\n" + "Score: " + score + "\n" + "Time: " + labelTimeValue->Text;
							MessageBox::Show(endGameString, "Congratulations!", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
							recordPlayerScore(labelPlayerValue->Text, labelScoreValue->Text, labelTimeValue->Text);

							this->Close();
						}
					}
					else {
						//user placed the queen in a bad location, take 50 points away
						score -= 50;
						labelScoreValue->Text = "" + score;

						pictureBoxGameResponse->ImageLocation = "Sad.png";

						SoundPlayer^ soundEffect = gcnew SoundPlayer("C:\\windows\\media\\ringout.wav");
						soundEffect->Play();
					}
				}
			}
			catch (Exception^ e) {
				//user typed in an invalid quadrant
				//System::Diagnostics::Debug::WriteLine("addQueen method \n\n" + e);
				labelInputResponse->Text = "Invalid Input: A - H | 1 - 8";
				labelInputResponse->ForeColor = Color::Red;
			}
		}

		private: System::Void removeQueen(String^ quadrant) {
			try {
				//see if the quadrant the user typed in is valid by attempting to look it up in the list
				if (queenLocations[quadrant] == false) {
					//this quadrant already has a queen, invalid input
					labelInputResponse->Text = "No queen found at " + quadrant;
					labelInputResponse->ForeColor = Color::Red;
				}
				else {
					//this quadrant is free, place the queen by showing the image
					numQueens--;
					labelInputResponse->Text = "Queen removed from " + quadrant;
					labelInputResponse->ForeColor = Color::Green;

					queenLocations[quadrant] = false;
					PictureBox^ quadrantImage = (PictureBox^)panelChessboard->Controls->Find(quadrant, true)[0];
					quadrantImage->Hide();
				}
			}
			catch (Exception^ e) {
				//user typed in an invalid quadrant
				//System::Diagnostics::Debug::WriteLine("addQueen method \n\n" + e);
				labelInputResponse->Text = "Invalid Input: A - H | 1 - 8";
				labelInputResponse->ForeColor = Color::Red;
			}
		}

		private: int queensQuadrant(int queenNumber) {
			int counter = 0;

			//loop through the whole dictionary and check if theres a queen at that location
			for (int index = 0; index < numOfSquares; index++) {
				if (queenLocations[keysList[index]] == true) {
					//found a queen!
					if (counter == queenNumber) {
						//and its the one we were looking for
						System::Diagnostics::Debug::WriteLine("Queen Located at: " + index + " : " + keysList[index]);

						return index;
					}
					else {
						//found the wrong queen, continue the search
						counter++;
					}
				}
			}
		}

		private: bool allQueensSafe(int queenLocation, int checkLocation, bool verticalFlag, bool horizontalFlag, bool diagonalFlagTLBR, bool diagonalFlagTRBL, bool directionFlag) {
			if (verticalFlag == false) {
				//limit the movement of checking the vertical direction				
				if (directionFlag == false) {
					if (checkLocation > (queenLocation + squaresPerRow - (queenLocation % squaresPerRow) -1)) {
						System::Diagnostics::Debug::WriteLine("Vertical Check Done [Queen] = " + queenLocation);
						directionFlag = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move Up " + checkLocation);
						return allQueensSafe(queenLocation, checkLocation + 1, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
				else if (directionFlag == true) {
					if (checkLocation < (queenLocation - (queenLocation % squaresPerRow))) {
						System::Diagnostics::Debug::WriteLine("Vertical Check Done (Both Ways) [Queen] = " + queenLocation);
						directionFlag = false;
						verticalFlag = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move Down " + checkLocation);
						return allQueensSafe(queenLocation, checkLocation - 1, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
			}
			else if (horizontalFlag == false) {
				if (directionFlag == false) {
					if (checkLocation > (numOfSquares - 1)) {
						System::Diagnostics::Debug::WriteLine("Horizontal Check Done [Queen] = " + queenLocation);
						directionFlag = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move Right " + checkLocation);
						return allQueensSafe(queenLocation, checkLocation + squaresPerRow, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
				else if (directionFlag == true) {
					if (checkLocation < 0) {
						System::Diagnostics::Debug::WriteLine("Horizontal Check Done (Both Ways) for Queen at Index: " + queenLocation);
						directionFlag = false;
						horizontalFlag = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);

					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move Left " + checkLocation);
						return allQueensSafe(queenLocation, checkLocation - squaresPerRow, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
			}
			else if (diagonalFlagTLBR == false) {
				if (directionFlag == false) {
					if (((checkLocation + 1) % squaresPerRow == 0) || (checkLocation < squaresPerRow)) {
						System::Diagnostics::Debug::WriteLine("Diagonal TLBR Check Done [Queen] = " + queenLocation);
						directionFlag = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);

					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move TL - BR Up");
						return allQueensSafe(queenLocation, checkLocation - (squaresPerRow - 1), verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
				else if (directionFlag == true) {
					if ((checkLocation % squaresPerRow == 0) || (checkLocation > (numOfSquares - 1))) {
						System::Diagnostics::Debug::WriteLine("Diagonal TLBR Check Done (Both Ways) [Queen] = " + queenLocation);
						directionFlag = false;
						diagonalFlagTLBR = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move TL - BR Dowm");
						return allQueensSafe(queenLocation, checkLocation + (squaresPerRow - 1), verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
			}
			else if (diagonalFlagTRBL == false) {
				if (directionFlag == false) {
					if (((checkLocation + 1) % squaresPerRow == 0) || (checkLocation > (numOfSquares - 1))) {
						System::Diagnostics::Debug::WriteLine("Diagonal TRBL Check Done [Queen] = " + queenLocation);
						directionFlag = true;
						return allQueensSafe(queenLocation, queenLocation, verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
					else {
						if (foundQueen(queenLocation, checkLocation)) {
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move TR - BL UP");
						return allQueensSafe(queenLocation, checkLocation + (squaresPerRow + 1), verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);

					}
				}
				else if (directionFlag == true) {
					if ((checkLocation % numOfSquares == 0) || (checkLocation < 0)) {
						System::Diagnostics::Debug::WriteLine("Diagonal TRBL Check Done (Both Ways) [Queen] = " + queenLocation);
						return true;
					}
					else {
						if(foundQueen(queenLocation, checkLocation)){
							return false;
						}
						System::Diagnostics::Debug::WriteLine("Move TR - BL Dowm");
						return allQueensSafe(queenLocation, checkLocation - (squaresPerRow + 1), verticalFlag, horizontalFlag, diagonalFlagTLBR, diagonalFlagTRBL, directionFlag);
					}
				}
			}
		}

		private: bool foundQueen(int queenLocation, int checkLocation) {
			if ((checkLocation > 0) && (checkLocation < (numOfSquares - 1))) {
				if (queenLocations[keysList[checkLocation]] == true) {
					if (queenLocation != checkLocation) {
						//this wasn't a false positive 
						//a queen was found in the danger zone, return false and stop all other checks
						System::Diagnostics::Debug::WriteLine("[Queen] = " + queenLocation + " found another [Queen] = " + checkLocation);
						return true;
					}
				}
			}
			return false;
		}

		private: System::Void recordPlayerScore(String^ player, String^ score, String^ time) {
			try {
				//also get numQueens global variable
				//create a new connection to the SQL Server and open it
				SqlConnection^ connection = gcnew SqlConnection("Data Source=McMahon-Laptop;Initial Catalog=Leaderboard;Persist Security Info=True;User ID=sa;Password=?sa");
				connection->Open();

				//sql query will insert a new row into the leaderboard table with users results
				String^ sql = "INSERT INTO Leaderboard(Name,Number_of_Queens,Time,Score) VALUES('" + player + "', '" + numQueens + "', '" + time + "', '" + score + "');";

				//execute the sql command
				SqlCommand^ command = gcnew SqlCommand(sql, connection);
				SqlDataReader^ rowReader = command->ExecuteReader();
			}
			catch (Exception^ e) {
				//somethings gone terribly wrong...
				System::Diagnostics::Debug::WriteLine("Writing score to database \n\n" + e);
			}
		}
	};
}