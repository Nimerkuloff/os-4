#pragma once
#include "windows.h"
#include <vector>
#include "worker.h"

namespace part1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	int toNewLine1 = 0;
	int toNewLine2 = 0;

	Worker    worker;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RadioButton^ radioButton5;

	private: System::ComponentModel::IContainer^ components;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->label1->Location = System::Drawing::Point(13, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 12);
			this->label1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoEllipsis = true;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->label2->Location = System::Drawing::Point(264, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 12);
			this->label2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(660, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 49);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ON";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(660, 400);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 49);
			this->button2->TabIndex = 3;
			this->button2->Text = L"OFF";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(537, 71);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(254, 225);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(24, 189);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(62, 17);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Nothing";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::RadioButton5_MouseClick);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(24, 156);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(79, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Semaphore";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::RadioButton4_MouseClick);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(24, 121);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(53, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Event";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::RadioButton3_MouseClick);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(24, 86);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(54, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Mutex";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::RadioButton2_MouseClick);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(24, 49);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(95, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Critical Section";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::RadioButton1_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(835, 490);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion



	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		worker.startWorkBoth();
		Sleep(150);
			print1();
			print2();
		
	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		clearLabel(1);
		clearLabel(2);

		toNewLine1 = 0;
		toNewLine2 = 0;
		worker.stopWork();
		worker.setData(0);
	}

	void print1() {
		for each (int e in worker.getLog1()) {
			label1->Text += e.ToString() + " ";

			toNewLine1++;
			if (toNewLine1 == 15) {
				label1->Text += "\n\n";
				toNewLine1 = 0;
			}


		}


	}
	void print2() {

		for each (int e in worker.getLog2()) {
			label2->Text += e.ToString() + " ";
			toNewLine2++;
			if (toNewLine2 == 15) {
				label2->Text += "\n\n";
				toNewLine2 = 0;
			}
		}
		


	}
	void clearLabel(int num)
	{
		if (num == 1) label1->Text = "";
		if (num == 2) label2->Text = "";
	}

	
	private: System::Void RadioButton1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		worker.setSelection(1);
	}
	private: System::Void RadioButton2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		worker.setSelection(2);
	}
	private: System::Void RadioButton3_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		worker.setSelection(3);
	}
	private: System::Void RadioButton4_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		worker.setSelection(4);
	}
	private: System::Void RadioButton5_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		worker.setSelection(0);
	}

	
};
}
