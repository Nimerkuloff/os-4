#pragma once
#include "rworker.h"
namespace lab2
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int toNewLine1 = 0;
	int toNewLine2 = 0;

	RWorker    worker;
	
	public ref class MyForm : public System::Windows::Forms::Form
	{

		public:
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

		protected:

		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button2;





	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


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
						this->components = (gcnew System::ComponentModel::Container());
						this->button1 = (gcnew System::Windows::Forms::Button());
						this->button2 = (gcnew System::Windows::Forms::Button());
						this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
						this->label1 = (gcnew System::Windows::Forms::Label());
						this->label2 = (gcnew System::Windows::Forms::Label());
						this->SuspendLayout();
						// 
						// button1
						// 
						this->button1->Location = System::Drawing::Point(561, 245);
						this->button1->Name = L"button1";
						this->button1->Size = System::Drawing::Size(110, 46);
						this->button1->TabIndex = 2;
						this->button1->Text = L"Пуск";
						this->button1->UseVisualStyleBackColor = true;
						this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
						// 
						// button2
						// 
						this->button2->Location = System::Drawing::Point(561, 297);
						this->button2->Name = L"button2";
						this->button2->Size = System::Drawing::Size(110, 46);
						this->button2->TabIndex = 3;
						this->button2->Text = L"Выход";
						this->button2->UseVisualStyleBackColor = true;
						this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
						// 
						// timer1
						// 
						this->timer1->Enabled = true;
						this->timer1->Interval = 10;
						this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
						// 
						// label1
						// 
						this->label1->AutoSize = true;
						this->label1->Location = System::Drawing::Point(12, 9);
						this->label1->Name = L"label1";
						this->label1->Size = System::Drawing::Size(0, 13);
						this->label1->TabIndex = 9;
						// 
						// label2
						// 
						this->label2->AutoSize = true;
						this->label2->Location = System::Drawing::Point(248, 9);
						this->label2->Name = L"label2";
						this->label2->Size = System::Drawing::Size(0, 13);
						this->label2->TabIndex = 10;
						// 
						// MyForm
						// 
						this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
						this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
						this->ClientSize = System::Drawing::Size(693, 377);
						this->Controls->Add(this->label2);
						this->Controls->Add(this->label1);
						this->Controls->Add(this->button2);
						this->Controls->Add(this->button1);
						this->MaximizeBox = false;
						this->MaximumSize = System::Drawing::Size(709, 416);
						this->MinimizeBox = false;
						this->MinimumSize = System::Drawing::Size(709, 416);
						this->Name = L"MyForm";
						this->ShowIcon = false;
						this->ResumeLayout(false);
						this->PerformLayout();

					}
			#pragma endregion
		

		private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			worker.startWorkBoth();
		}

		private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			clearLabel(1);
			clearLabel(2);
			
			toNewLine1 = 0;
			toNewLine2 = 0;
			worker.stopWork();
		}

		private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			
			if (worker.isDataUpdated()) 
			{
				print1();
				print2();

			}
		}



				 void print1() {
					 
					label1->Text+=	worker.getLog1().ToString() + " ";
					 
					 toNewLine1++;
					 if (toNewLine1 == 15) {
						 label1->Text += "\n\n";
						 toNewLine1 = 0;
					 }
				 
					 
				 }
				 void print2() {
					 
					 label2->Text += worker.getLog2().ToString() + " ";
					 toNewLine2++;
					 if (toNewLine2 == 15) {
						 label2->Text += "\n\n";
						 toNewLine2 = 0;
					 }
				 
		 
				 }
		void clearLabel(int num)
		{
		if(num==1) label1->Text = "";
			if (num==2)label2->Text = "";
		}

};

}