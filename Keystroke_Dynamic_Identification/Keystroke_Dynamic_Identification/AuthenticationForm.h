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
	/// Summary for AuthenticationForm
	/// </summary>
	public ref class AuthenticationForm : public System::Windows::Forms::Form
	{
		int start = 0, end = 0;
		char symbol = 0, symbol_buf = 0;

		array<int>^ arr_pressing_time_counter = gcnew array<int>(94);
		array<int>^ arr_pressing_time_average = gcnew array<int>(94);
		array<int, 2>^ arr_pressing_time_range_min_max = gcnew array<int, 2>(94, 94);

		array<int, 2>^ arr_pressing_interval_counter = gcnew array<int, 2>(94, 94);
		array<int, 2>^ arr_pressing_interval_average = gcnew array<int, 2>(94, 94);
		array<int, 3>^ arr_pressing_interval_range_min_max = gcnew array<int, 3>(94, 94, 94);

	public:
		AuthenticationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

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

				if ((arr_pressing_time_range_min_max[i, 0] || arr_pressing_time_range_min_max[i, 1]) != 0) 
					listBox1->Items->Add(wchar_t(i + 32) + "\t" + arr_pressing_time_range_min_max[i, 0].ToString() + " - " + arr_pressing_time_range_min_max[i, 1].ToString() + "\n");

				file_pressing_time_range_min_max.seekg(3, file_pressing_time_range_min_max.ios_base::cur);

				for (int j = 0; j < 94; j++)
				{
					file_pressing_interval_range_min_max >> a;
					arr_pressing_interval_range_min_max[i, j, 0] = a;

					file_pressing_interval_range_min_max >> a;
					arr_pressing_interval_range_min_max[i, j, 1] = a;

					if ((arr_pressing_interval_range_min_max[i, j, 0] || arr_pressing_interval_range_min_max[i, j, 1]) != 0)
						listBox2->Items->Add(wchar_t(i + 32) + " - " + wchar_t(j + 32) + "\t" + arr_pressing_interval_range_min_max[i, j, 0].ToString() + " - " + arr_pressing_interval_range_min_max[i, j, 1].ToString() + "\n");

					file_pressing_interval_range_min_max.seekg(7, file_pressing_interval_range_min_max.ios_base::cur);
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AuthenticationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::ListBox^ listBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button1->Location = System::Drawing::Point(316, 282);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(325, 83);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Перевірити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AuthenticationForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(316, 220);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(325, 56);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AuthenticationForm::textBox1_KeyPress);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &AuthenticationForm::textBox1_KeyUp);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(316, 424);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(325, 57);
			this->label1->TabIndex = 2;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(312, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(329, 52);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Коефіцієнт\r\nдозволеного допуску  = 0";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(316, 64);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(325, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &AuthenticationForm::trackBar1_Scroll);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button2->Location = System::Drawing::Point(316, 484);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(325, 83);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Вихід";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AuthenticationForm::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 64);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(298, 212);
			this->listBox1->TabIndex = 7;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(647, 64);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(298, 212);
			this->listBox2->TabIndex = 8;
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(12, 368);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(298, 199);
			this->listBox3->TabIndex = 9;
			// 
			// listBox4
			// 
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Location = System::Drawing::Point(647, 368);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(298, 199);
			this->listBox4->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(316, 368);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(325, 56);
			this->label3->TabIndex = 11;
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(12, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(298, 52);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Еталон часу утримання клавіш";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(647, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(298, 52);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Еталон інтервалу між натисканням клавіш";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label6->Location = System::Drawing::Point(12, 280);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(298, 86);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Зіставлення поточних показників часу утримання клавіш з еталоном";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label7->Location = System::Drawing::Point(644, 279);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(301, 86);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Зіставлення поточних показників інтервалу між натисканням клавіш з еталоном";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(316, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(325, 110);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Введіть текст за тим же алгоритмом, що ї на етапі створення еталону.\r\nthe quick b"
				L"rown fox jumps over the lazy dog";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AuthenticationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 594);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AuthenticationForm";
			this->Text = L"AuthenticationForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		float counter_positive_identification = 0, counter_negative_identification = 0;
		listBox3->Items->Clear();
		listBox4->Items->Clear();
		listBox3->Items->Add("Межі еталону" + "\t|" + "Поточне середнє  |");
		listBox4->Items->Add("Межі еталону" + "\t|" + "Поточне середнє  |");
		for (int i = 0; i < 94; i++)
		{
			if (arr_pressing_time_average[i] == 0) continue;
			if (arr_pressing_time_average[i] >= arr_pressing_time_range_min_max[i, 0] && arr_pressing_time_average[i] <= arr_pressing_time_range_min_max[i, 1])
			{
				counter_positive_identification++;
				listBox3->Items->Add(wchar_t(i + 32) + "\t" + arr_pressing_time_range_min_max[i, 0].ToString() + " - " + arr_pressing_time_range_min_max[i, 1].ToString()
					+ "\t|\t" + arr_pressing_time_average[i] + "\t|" + " Влучання");
			}
			else
			{
				counter_negative_identification++;
				listBox3->Items->Add(wchar_t(i + 32) + "\t" + arr_pressing_time_range_min_max[i, 0].ToString() + " - " + arr_pressing_time_range_min_max[i, 1].ToString()
					+ "\t|\t" + arr_pressing_time_average[i] + "\t|" + " Не влучання");
			}

			for (int j = 0; j < 94; j++)
			{
				if (arr_pressing_interval_average[i, j] == 0) continue;
				if (arr_pressing_interval_average[i, j] >= arr_pressing_interval_range_min_max[i, j, 0] && arr_pressing_interval_average[i, j] <= arr_pressing_interval_range_min_max[i, j, 1])
				{
					counter_positive_identification++;
					listBox4->Items->Add(wchar_t(i + 32) + " - " + wchar_t(j + 32) + "\t" + arr_pressing_interval_range_min_max[i, j, 0].ToString() + " - " + arr_pressing_interval_range_min_max[i, j, 1].ToString()
						+ "\t|\t" + arr_pressing_interval_average[i, j] + "\t|" + " Влучання");
				}
				else
				{
					counter_negative_identification++;
					listBox4->Items->Add(wchar_t(i + 32) + " - " + wchar_t(j + 32) + "\t" + arr_pressing_interval_range_min_max[i, j, 0].ToString() + " - " + arr_pressing_interval_range_min_max[i, j, 1].ToString()
						+ "\t|\t" + arr_pressing_interval_average[i, j] + "\t|" + " Не влучання");

				}
			}
		}
		label3->Text = "В межах еталону: " + counter_positive_identification.ToString() + "\n"
			+ "Поза межами еталону: " + counter_negative_identification.ToString() + "\n";

		if ((counter_negative_identification / (counter_positive_identification + counter_negative_identification)) < (float(trackBar1->Value) / 100))
			label1->Text = "Аутентифікацію пройдено" + "\n"
			+ counter_negative_identification.ToString() + " / ( " + counter_positive_identification.ToString() + " + " + counter_negative_identification.ToString() + ") < " + (float(trackBar1->Value) / 100);
		else
			label1->Text = "Аутентифікацію не пройдено" + "\n"
			+ counter_negative_identification.ToString() + " / ( " + counter_positive_identification.ToString() + " + " + counter_negative_identification.ToString() + ") >= " + (float(trackBar1->Value) / 100);;
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
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		label2->Text = "Коефіцієнт\nдозволеного допуску = " + trackBar1->Value.ToString() + "%";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		current_path(current_path().parent_path().parent_path());
		Close();
	}



};
}
