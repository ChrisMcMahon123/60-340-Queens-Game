#include <windows.h>
#include "dataStructureLeaderboard.h"

namespace mcmah113Assignment2 {

	using namespace System;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class mcmah113Leaderboard : public System::Windows::Forms::Form {
	public:
		mcmah113Leaderboard(void) {
			InitializeComponent();
			//create a connection to the database and retrieve the top 10 scores
			loadHighScores();
		}

	protected:
		~mcmah113Leaderboard() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  buttonClose;
	private: System::Windows::Forms::Label^  labelTitle;
	private: System::Windows::Forms::DataGridView^  dataGridViewLeaderboard;

	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void) {
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mcmah113Leaderboard::typeid));
			this->dataGridViewLeaderboard = (gcnew System::Windows::Forms::DataGridView());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLeaderboard))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewLeaderboard
			// 
			this->dataGridViewLeaderboard->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewLeaderboard->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridViewLeaderboard->Location = System::Drawing::Point(19, 57);
			this->dataGridViewLeaderboard->MultiSelect = false;
			this->dataGridViewLeaderboard->Name = L"dataGridViewLeaderboard";
			this->dataGridViewLeaderboard->ReadOnly = true;
			this->dataGridViewLeaderboard->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridViewLeaderboard->Size = System::Drawing::Size(478, 251);
			this->dataGridViewLeaderboard->TabIndex = 0;
			// 
			// buttonClose
			// 
			this->buttonClose->Location = System::Drawing::Point(374, 8);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(123, 33);
			this->buttonClose->TabIndex = 1;
			this->buttonClose->Text = L"Close";
			this->buttonClose->UseVisualStyleBackColor = true;
			this->buttonClose->Click += gcnew System::EventHandler(this, &mcmah113Leaderboard::buttonClose_Click);
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(12, 8);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(224, 37);
			this->labelTitle->TabIndex = 2;
			this->labelTitle->Text = L"Top 10 Scores";
			// 
			// mcmah113Leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(518, 320);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->dataGridViewLeaderboard);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(534, 359);
			this->MinimumSize = System::Drawing::Size(534, 359);
			this->Name = L"mcmah113Leaderboard";
			this->Text = L"mcmah113Leaderboard";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLeaderboard))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void buttonClose_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}

		private: System::Void loadHighScores() {
			try {
				//create a new connection to the SQL Server and open it
				SqlConnection^ connection = gcnew SqlConnection("Data Source=McMahon-Laptop;Initial Catalog=Leaderboard;Persist Security Info=True;User ID=sa;Password=?sa");
				connection->Open();

				//sql query that will grab the top 10 results and order them in order of highest to lowest also assigning a rank position to each
				String^ sql = "SELECT ROW_NUMBER() OVER(ORDER BY first.Score DESC) AS 'Rank', * FROM (SELECT TOP 10 Name, CONVERT(VARCHAR(10), Date, 101) AS 'Date', Number_of_Queens AS 'Number of Queens', Time, Score FROM Leaderboard Order By Score DESC) AS first ORDER BY first.Score DESC;";

				//execute the sql command and store its results 
				SqlCommand^ command = gcnew SqlCommand(sql, connection);
				SqlDataReader^ rowReader = command->ExecuteReader();
				
				//create list of a custom class that will store all of the database column values
				List<dataStructureLeaderboard^>^ dataStructure = gcnew List<dataStructureLeaderboard^>();

				//loop through the sql queries results and store them in the list
				while (rowReader->Read()) {
					dataStructure->Add(gcnew dataStructureLeaderboard(rowReader["Rank"]->ToString(),rowReader["Name"]->ToString(), rowReader["Date"]->ToString(), rowReader["Number of Queens"]->ToString(), rowReader["Time"]->ToString(), rowReader["Score"]->ToString()));
				}
				
				connection->Close();

				//set the source of the datagrid, columns will be auto generated
				dataGridViewLeaderboard->DataSource = dataStructure;
				dataGridViewLeaderboard->Refresh();
			}
			catch (Exception^ e) {
				//somethings gone terribly wrong...
				System::Diagnostics::Debug::WriteLine("Writing score to database \n\n" + e);
			}
		}
	};
}