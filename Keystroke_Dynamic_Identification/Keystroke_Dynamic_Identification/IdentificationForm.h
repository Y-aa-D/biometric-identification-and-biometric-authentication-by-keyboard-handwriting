#pragma once
#include <msclr/marshal.h>
#include <msclr/marshal_atl.h>
#include <msclr/marshal_cppstd.h>
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
	using namespace msclr::interop;

	/// <summary>
	/// Summary for IdentificationForm
	/// </summary>
	public ref class IdentificationForm : public System::Windows::Forms::Form
	{
		int start = 0, end = 0, counter_positive_result = 0;
		char symbol = 0, symbol_buf = 0;

		array<int>^ arr_pressing_time_counter = gcnew array<int>(94);
		array<int>^ arr_pressing_time_average = gcnew array<int>(94);
		array<int, 2>^ arr_pressing_time_range_min_max = gcnew array<int, 2>(94, 94);

		array<int, 2>^ arr_pressing_interval_counter = gcnew array<int, 2>(94, 94);
		array<int, 2>^ arr_pressing_interval_average = gcnew array<int, 2>(94, 94);
		array<int, 3>^ arr_pressing_interval_range_min_max = gcnew array<int, 3>(94, 94, 94);

	public:
		IdentificationForm(void)
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
		~IdentificationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	protected:
	private: System::ComponentModel::IContainer^ components;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 646);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1002, 74);
			this->label1->TabIndex = 0;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button2->Location = System::Drawing::Point(516, 723);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(498, 83);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Вихід";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &IdentificationForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button1->Location = System::Drawing::Point(12, 723);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(498, 83);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Ідентифікація";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IdentificationForm::button1_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(516, 129);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(498, 407);
			this->listBox2->TabIndex = 10;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 542);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1002, 101);
			this->textBox1->TabIndex = 14;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &IdentificationForm::textBox1_KeyPress);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &IdentificationForm::textBox1_KeyUp);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 129);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(498, 407);
			this->listBox1->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(238, 16);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(590, 110);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Введіть текст за тим же алгоритмом, що ї на етапі створення еталону.\r\nthe quick b"
				L"rown fox jumps over the lazy dog";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// IdentificationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1026, 818);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"IdentificationForm";
			this->Text = L"IdentificationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		listBox1->Items->Clear();
		listBox2->Items->Clear();

		for (const auto dir_entry : std::filesystem::directory_iterator{ current_path() })
		{
			current_path(dir_entry);

			std::ifstream file_pressing_time_range_min_max("file_pressing_time_range_min_max.txt");
			file_pressing_time_range_min_max.seekg(2, file_pressing_time_range_min_max.ios_base::cur);

			std::ifstream file_pressing_interval_range_min_max("file_pressing_interval_range_min_max.txt");
			file_pressing_interval_range_min_max.seekg(6, file_pressing_interval_range_min_max.ios_base::cur);

			for (int i = 0; i < 94; i++)
			{
				int a;

				file_pressing_time_range_min_max >> a;
				arr_pressing_time_range_min_max[i, 0] = a;

				file_pressing_time_range_min_max >> a;
				arr_pressing_time_range_min_max[i, 1] = a;

				file_pressing_time_range_min_max.seekg(3, file_pressing_time_range_min_max.ios_base::cur);

				for (int j = 0; j < 94; j++)
				{
					file_pressing_interval_range_min_max >> a;
					arr_pressing_interval_range_min_max[i, j, 0] = a;

					file_pressing_interval_range_min_max >> a;
					arr_pressing_interval_range_min_max[i, j, 1] = a;

					file_pressing_interval_range_min_max.seekg(7, file_pressing_interval_range_min_max.ios_base::cur);
				}
			}

			file_pressing_time_range_min_max.close();
			file_pressing_interval_range_min_max.close();

			int counter_positive_time = 0, counter_positive_interval = 0;

			listBox1->Items->Add(marshal_as<String^>(dir_entry.path().filename().string()));
			listBox1->Items->Add("Межі еталону" + "\t|" + "Поточне середнє  |");

			listBox2->Items->Add(marshal_as<String^>(dir_entry.path().filename().string()));
			listBox2->Items->Add("Межі еталону" + "\t|" + "Поточне середнє  |");

			for (int i = 0; i < 94; i++)
			{
				if (arr_pressing_time_average[i] == 0) continue;
				if (arr_pressing_time_average[i] >= arr_pressing_time_range_min_max[i, 0] && arr_pressing_time_average[i] <= arr_pressing_time_range_min_max[i, 1])
				{
					counter_positive_time++;
					listBox1->Items->Add(wchar_t(i + 32) + "\t" + arr_pressing_time_range_min_max[i, 0].ToString() + " - " + arr_pressing_time_range_min_max[i, 1].ToString()
						+ "\t|\t" + arr_pressing_time_average[i] + "\t|" + " Влучання");
				}
				else
				{
					listBox1->Items->Add(wchar_t(i + 32) + "\t" + arr_pressing_time_range_min_max[i, 0].ToString() + " - " + arr_pressing_time_range_min_max[i, 1].ToString()
						+ "\t|\t" + arr_pressing_time_average[i] + "\t|" + " Не влучання");
				}

				for (int j = 0; j < 94; j++)
				{
					if (arr_pressing_interval_average[i, j] == 0) continue;
					if (arr_pressing_interval_average[i, j] >= arr_pressing_interval_range_min_max[i, j, 0] && arr_pressing_interval_average[i, j] <= arr_pressing_interval_range_min_max[i, j, 1])
					{
						counter_positive_interval++;
						listBox2->Items->Add(wchar_t(i + 32) + " - " + wchar_t(j + 32) + "\t" + arr_pressing_interval_range_min_max[i, j, 0].ToString() + " - " + arr_pressing_interval_range_min_max[i, j, 1].ToString()
							+ "\t|\t" + arr_pressing_interval_average[i, j] + "\t|" + " Влучання");
					}
					else
					{
						listBox2->Items->Add(wchar_t(i + 32) + " - " + wchar_t(j + 32) + "\t" + arr_pressing_interval_range_min_max[i, j, 0].ToString() + " - " + arr_pressing_interval_range_min_max[i, j, 1].ToString()
							+ "\t|\t" + arr_pressing_interval_average[i, j] + "\t|" + " Не влучання");
					}
				}
			}

			listBox1->Items->Add("Результат по характеристиці часу утримання клавіши: " + counter_positive_time + " влучень");
			listBox1->Items->Add("");
			listBox2->Items->Add("Результат по характеристиці часу інтервалу між натисканням клавіш: " + counter_positive_interval + " влучень");
			listBox2->Items->Add("");

			if (counter_positive_time + counter_positive_interval > counter_positive_result)
			{
				counter_positive_result = counter_positive_time + counter_positive_interval;
				label1->Text = "Ваш ідентифікатор найбільш близький до еталону користувача " + marshal_as<String^>(current_path().filename().string());
			}
		}

		current_path(current_path().parent_path());
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		start = clock();

		symbol = e->KeyChar;

		arr_pressing_time_counter[symbol - 32]++;

		if (symbol_buf > 31 && symbol_buf < 128)
		{
			arr_pressing_interval_counter[symbol_buf - 32, symbol - 32]++;

			arr_pressing_interval_average[symbol_buf - 32, symbol - 32] = //Середній час інтервалу між натисканням клавіш
				((arr_pressing_interval_counter[symbol_buf - 32, symbol - 32] - 1) *
					arr_pressing_interval_average[symbol_buf - 32, symbol - 32] + (start - end)) /
				arr_pressing_interval_counter[symbol_buf - 32, symbol - 32];
		}
		symbol_buf = symbol;
	}
	private: System::Void textBox1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		end = clock();

		if (symbol > 31 && symbol < 128)
		{
			arr_pressing_time_average[symbol - 32] = //Середній час утримання клавіши
				((arr_pressing_time_counter[symbol - 32] - 1) *
					arr_pressing_time_average[symbol - 32] + (end - start)) /
				arr_pressing_time_counter[symbol - 32];
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		current_path(current_path().parent_path());
		Close();
	}
};

}
