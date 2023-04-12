#pragma once
#include <fstream>
#include <filesystem>

namespace KeystrokeDynamicIdentification {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::filesystem;

	/// <summary>
	/// Summary for TrainingForm
	/// </summary>

	public ref class TrainingForm : public System::Windows::Forms::Form
	{
		int start = 0, end = 0;
		char symbol = 0, symbol_buf = 0;

		array<int>^ arr_pressing_time_counter = gcnew array<int>(94);
		array<int>^ arr_pressing_time_average = gcnew array<int>(94);
		array<int>^ arr_pressing_time_average_deviation = gcnew array<int>(94);
		array<int, 2>^ arr_pressing_time_range_min_max = gcnew array<int, 2>(94, 94);

		array<int, 2>^ arr_pressing_interval_counter = gcnew array<int, 2>(94, 94);
		array<int, 2>^ arr_pressing_interval_average = gcnew array<int, 2>(94, 94);
		array<int, 2>^ arr_pressing_interval_average_deviation = gcnew array<int, 2>(94, 94);
		array<int, 3>^ arr_pressing_interval_range_min_max = gcnew array<int, 3>(94, 94, 94);
		array<float>^ arr_pressing_interval_range_min_ma1x = gcnew array<float>(90);		

	public:
		TrainingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			std::ofstream file_pressing_time("file_pressing_time.txt");
			std::ofstream file_pressing_interval("file_pressing_interval.txt");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TrainingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	protected:
	private: System::ComponentModel::Container^ components;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TrainingForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(16, 257);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(374, 147);
			this->textBox1->TabIndex = 3;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TrainingForm::textBox1_KeyPress);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TrainingForm::textBox1_KeyUp);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button1->Location = System::Drawing::Point(16, 413);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 30);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Зберегти еталон";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TrainingForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button2->Location = System::Drawing::Point(396, 413);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 30);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Вихід";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TrainingForm::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(396, 13);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(66, 394);
			this->listBox1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(378, 245);
			this->label1->TabIndex = 8;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(468, 13);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(80, 394);
			this->listBox2->TabIndex = 9;
			// 
			// TrainingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 451);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TrainingForm";
			this->Text = L"TrainingForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
	{
		symbol = e->KeyChar;

		start = clock();

		arr_pressing_time_counter[symbol - 32]++;

		if (symbol_buf > 31 && symbol_buf < 128)
		{
			arr_pressing_interval_counter[symbol_buf - 32, symbol - 32]++;

			std::fstream file_pressing_interval("file_pressing_interval.txt");
			file_pressing_interval.seekg(0, file_pressing_interval.end);
			file_pressing_interval << symbol_buf << " - " << symbol << " " << (start - end) << "\n";
			file_pressing_interval.close();

			listBox2->Items->Add(wchar_t(symbol_buf) + " - " + wchar_t(symbol) + " " + (start - end) + "\n");

			arr_pressing_interval_average[symbol_buf - 32, symbol - 32] = //Середній час інтервалу між натисканням клавіш
				((arr_pressing_interval_counter[symbol_buf - 32, symbol - 32] - 1) *
					arr_pressing_interval_average[symbol_buf - 32,symbol - 32] + (start - end)) /
				arr_pressing_interval_counter[symbol_buf - 32,symbol - 32];

			arr_pressing_interval_average_deviation[symbol_buf - 32,symbol - 32] = //Середнє відхилення часу інтервалу між натисканням клавіш
				sqrt((((arr_pressing_interval_counter[symbol_buf - 32,symbol - 32] - 2) *
					pow(arr_pressing_interval_average_deviation[symbol_buf - 32,symbol - 32], 2)) +
					pow((start - end) - arr_pressing_interval_average[symbol_buf - 32,symbol - 32], 2)) /
					(arr_pressing_interval_counter[symbol_buf - 32,symbol - 32] - 1));

			arr_pressing_interval_range_min_max[symbol_buf - 32,symbol - 32, 0] = //Нижня границя відхилення часу інтервалу між натисканням клавіш
				arr_pressing_interval_average[symbol_buf - 32,symbol - 32] -
				(2.262 * arr_pressing_interval_average_deviation[symbol_buf - 32,symbol - 32]);
			if (arr_pressing_interval_range_min_max[symbol_buf - 32,symbol - 32, 0] < 0) arr_pressing_interval_range_min_max[symbol_buf - 32,symbol - 32,0] = 0;

			arr_pressing_interval_range_min_max[symbol_buf - 32,symbol - 32, 1] = //Верхня границя відхилення часу інтервалу між натисканням клавіш
				arr_pressing_interval_average[symbol_buf - 32,symbol - 32] +
				(2.262 * arr_pressing_interval_average_deviation[symbol_buf - 32, symbol - 32]);
		}
		symbol_buf = symbol;
	}
	private: System::Void textBox1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		end = clock();

		if (symbol > 31 && symbol < 128 )
		{
			std::fstream file_pressing_time("file_pressing_time.txt");
			file_pressing_time.seekg(0, file_pressing_time.end);
			file_pressing_time << symbol << " " << (end - start) << "\n";
			file_pressing_time.close();

			listBox1->Items->Add(wchar_t(symbol) + " " + (end - start) + "\n");

			arr_pressing_time_average[symbol - 32] = //Середній час утримання клавіши
				((arr_pressing_time_counter[symbol - 32] - 1) *
					arr_pressing_time_average[symbol - 32] + (end - start)) /
				arr_pressing_time_counter[symbol - 32];

			arr_pressing_time_average_deviation[symbol - 32] = //Середнє відхилення часу утримання клавіши
				sqrt((((arr_pressing_time_counter[symbol - 32] - 2) *
					pow(arr_pressing_time_average_deviation[symbol - 32], 2)) +
					pow((end - start) - arr_pressing_time_average[symbol - 32], 2)) /
					(arr_pressing_time_counter[symbol - 32] - 1));

			arr_pressing_time_range_min_max[symbol - 32, 0] = //Нижня границя відхилення часу утримання клавіши 
				arr_pressing_time_average[symbol - 32] -
				(2.262 * arr_pressing_time_average_deviation[symbol - 32]);
			if (arr_pressing_time_range_min_max[symbol - 32, 0] < 0) arr_pressing_time_range_min_max[symbol - 32, 0] = 0;

			arr_pressing_time_range_min_max[symbol - 32, 1] = //Верхня границя відхилення часу утримання клавіши 
				arr_pressing_time_average[symbol - 32] +
				(2.262 * arr_pressing_time_average_deviation[symbol - 32]);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		std::ofstream file_pressing_time_counter_average_deviation("file_pressing_time_counter_average_deviation.txt");
		std::ofstream file_pressing_time_range_min_max("file_pressing_time_range_min_max.txt");

		std::ofstream file_pressing_interval_counter_average_deviation("file_pressing_interval_counter_average_deviation.txt");
		std::ofstream file_pressing_interval_range_min_max("file_pressing_interval_range_min_max.txt");
		symbol = 32;
		for (int i = 0; i < 94; i++)
		{
			file_pressing_time_counter_average_deviation << char(symbol + i) << " " << arr_pressing_time_counter[i] << " " << arr_pressing_time_average[i] << " " << arr_pressing_time_average_deviation[i] << "\n";
			file_pressing_time_range_min_max << char(symbol + i) << " " << arr_pressing_time_range_min_max[i,0] << " " << arr_pressing_time_range_min_max[i,1] << "\n";
			for (int j = 0; j < 94; j++)
			{
				file_pressing_interval_counter_average_deviation << char(symbol + i) << " - " << char(symbol + j) << " " << arr_pressing_interval_counter[i,j] << " " << arr_pressing_interval_average[i,j] << " " << arr_pressing_interval_average_deviation[i,j] << "\n";
				file_pressing_interval_range_min_max << char(symbol + i) << " - " << char(symbol + j) << " " << arr_pressing_interval_range_min_max[i,j,0] << " " << arr_pressing_interval_range_min_max[i,j,1] << "\n";
			}
		}
		file_pressing_time_counter_average_deviation.close();
		file_pressing_time_range_min_max.close();

		file_pressing_interval_counter_average_deviation.close();
		file_pressing_interval_range_min_max.close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		current_path(current_path().parent_path().parent_path());
		Close();
	}
};
}