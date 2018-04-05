#include <windows.h>
#include "mcmah113ChessBoard.h"
#include "mcmah113Leaderboard.h"

namespace mcmah113Assignment2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class mcmah113Start : public System::Windows::Forms::Form {
	public:
		mcmah113Start(void) {
			InitializeComponent();
		}

	protected:
		~mcmah113Start() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  buttonGame;
	private: System::Windows::Forms::Button^  buttonLeaderboard;
	private: System::Windows::Forms::Button^  buttonExit;
	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mcmah113Start::typeid));
			this->buttonGame = (gcnew System::Windows::Forms::Button());
			this->buttonLeaderboard = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonGame
			// 
			this->buttonGame->Location = System::Drawing::Point(25, 13);
			this->buttonGame->Name = L"buttonGame";
			this->buttonGame->Size = System::Drawing::Size(164, 49);
			this->buttonGame->TabIndex = 0;
			this->buttonGame->Text = L"8 Queens Game";
			this->buttonGame->UseVisualStyleBackColor = true;
			this->buttonGame->Click += gcnew System::EventHandler(this, &mcmah113Start::button1_Click);
			// 
			// buttonLeaderboard
			// 
			this->buttonLeaderboard->Location = System::Drawing::Point(25, 68);
			this->buttonLeaderboard->Name = L"buttonLeaderboard";
			this->buttonLeaderboard->Size = System::Drawing::Size(164, 49);
			this->buttonLeaderboard->TabIndex = 1;
			this->buttonLeaderboard->Text = L"Leader Board";
			this->buttonLeaderboard->UseVisualStyleBackColor = true;
			this->buttonLeaderboard->Click += gcnew System::EventHandler(this, &mcmah113Start::button2_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->Location = System::Drawing::Point(25, 123);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(164, 49);
			this->buttonExit->TabIndex = 2;
			this->buttonExit->Text = L"Exit";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &mcmah113Start::button3_Click);
			// 
			// mcmah113Start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(216, 184);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonLeaderboard);
			this->Controls->Add(this->buttonGame);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(232, 223);
			this->MinimumSize = System::Drawing::Size(232, 223);
			this->Name = L"mcmah113Start";
			this->Text = L"mcmah113Start";
			this->ResumeLayout(false);

		}

		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			mcmah113Chessboard^ chessboard = gcnew mcmah113Chessboard;
			chessboard->ShowDialog();
		}

		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			mcmah113Leaderboard^ leaderboard = gcnew mcmah113Leaderboard;
			leaderboard->ShowDialog();
		}

		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}
	};
}