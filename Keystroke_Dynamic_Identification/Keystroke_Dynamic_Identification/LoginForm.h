#pragma once
#include "AuthenticationForm.h"
#include "IdentificationForm.h"
#include "TrainingForm.h"
#include <direct.h>
#include <msclr/marshal.h>
#include <msclr/marshal_atl.h>
#include <msclr/marshal_cppstd.h>

namespace KeystrokeDynamicIdentification {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_mkdir("База даних");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button1->Location = System::Drawing::Point(233, 127);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Аутентифікація";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button2->Location = System::Drawing::Point(72, 127);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(155, 58);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Створення еталону";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LoginForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox1->Location = System::Drawing::Point(72, 84);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(477, 37);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(72, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(477, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Логін";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->button3->Location = System::Drawing::Point(394, 127);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(155, 58);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Ідентифікація";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &LoginForm::button3_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(653, 274);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"LoginForm";
			this->Text = L"Ідентифікація та аутентифікація за клавіатурним почерком";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (textBox1->Text == "") MessageBox::Show("Введіть логін", "Помилка", MessageBoxButtons::OK);
		else
		{
			marshal_context ctx;
			if (_chdir(ctx.marshal_as<const char*>("База даних//" + textBox1->Text)) == -1) MessageBox::Show("Користувача не знайдено", "Помилка", MessageBoxButtons::OK);
			else
			{
				AuthenticationForm^ ifr = gcnew AuthenticationForm();
				ifr->ShowDialog();
			}
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (textBox1->Text == "") MessageBox::Show("Введіть логін", "Помилка", MessageBoxButtons::OK);
		else
		{
			marshal_context ctx;
			_mkdir(ctx.marshal_as<const char*>("База даних//" + textBox1->Text));
			_chdir(ctx.marshal_as<const char*>("База даних//" + textBox1->Text));
			TrainingForm^ trf = gcnew TrainingForm();
			trf->ShowDialog();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (textBox1->Text != "") MessageBox::Show("Ідентифікація проводиться за ідентифікатором користувача, яким в даному випадку виступає характеристика Вашого клавіатурного почерку, а не логін", "Попередження", MessageBoxButtons::OK);
		_chdir("База даних//");
		IdentificationForm^ trf = gcnew IdentificationForm();
		trf->ShowDialog();
	}
	};
}
