#include <windows.h>

namespace mcmah113Assignment2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class mcmah113PlayerNameDialog : public System::Windows::Forms::Form {
	public:
		mcmah113PlayerNameDialog(void)
		{
			InitializeComponent();
			//

		}

	protected:
		~mcmah113PlayerNameDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonEnter;
	//needed to allow the parent form to acccess its value
	public: System::Windows::Forms::TextBox^  textBoxPlayerName;
	protected:

	protected:


	private: System::Windows::Forms::Label^  labelPlayerName;



	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mcmah113PlayerNameDialog::typeid));
			this->buttonEnter = (gcnew System::Windows::Forms::Button());
			this->textBoxPlayerName = (gcnew System::Windows::Forms::TextBox());
			this->labelPlayerName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonEnter
			// 
			this->buttonEnter->Enabled = false;
			this->buttonEnter->Location = System::Drawing::Point(228, 52);
			this->buttonEnter->Name = L"buttonEnter";
			this->buttonEnter->Size = System::Drawing::Size(99, 26);
			this->buttonEnter->TabIndex = 0;
			this->buttonEnter->Text = L"Enter";
			this->buttonEnter->UseVisualStyleBackColor = true;
			this->buttonEnter->Click += gcnew System::EventHandler(this, &mcmah113PlayerNameDialog::buttonEnter_Click);
			// 
			// textBoxPlayerName
			// 
			this->textBoxPlayerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxPlayerName->Location = System::Drawing::Point(12, 52);
			this->textBoxPlayerName->Name = L"textBoxPlayerName";
			this->textBoxPlayerName->Size = System::Drawing::Size(189, 26);
			this->textBoxPlayerName->TabIndex = 450;
			this->textBoxPlayerName->TextChanged += gcnew System::EventHandler(this, &mcmah113PlayerNameDialog::textBoxPlayerName_TextChanged);
			// 
			// labelPlayerName
			// 
			this->labelPlayerName->AutoSize = true;
			this->labelPlayerName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelPlayerName->Location = System::Drawing::Point(9, 18);
			this->labelPlayerName->Name = L"labelPlayerName";
			this->labelPlayerName->Size = System::Drawing::Size(164, 18);
			this->labelPlayerName->TabIndex = 457;
			this->labelPlayerName->Text = L"Please enter your name";
			// 
			// mcmah113PlayerNameDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 91);
			this->Controls->Add(this->labelPlayerName);
			this->Controls->Add(this->textBoxPlayerName);
			this->Controls->Add(this->buttonEnter);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(355, 130);
			this->MinimumSize = System::Drawing::Size(355, 130);
			this->Name = L"mcmah113PlayerNameDialog";
			this->Text = L"mcmah113PlayerNameDialog";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		private: System::Void textBoxPlayerName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			if (String::IsNullOrEmpty(textBoxPlayerName->Text) || String::IsNullOrWhiteSpace(textBoxPlayerName->Text)) {
				buttonEnter->Enabled = false;
			}
			else {
				buttonEnter->Enabled = true;
			}
		}
		private: System::Void buttonEnter_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}
	};
}
