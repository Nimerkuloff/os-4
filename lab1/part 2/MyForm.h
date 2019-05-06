#pragma once
#include <windows.h>
#include <vector>

namespace Project1
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	STARTUPINFO          sinfo;
	PROCESS_INFORMATION  pi;
	std::vector<PROCESS_INFORMATION> vector;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public: MyForm(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
	}
	protected: ~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // button1
				 // 
				 this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->button1->AutoSize = true;
				 this->button1->Location = System::Drawing::Point(12, 9);
				 this->button1->Margin = System::Windows::Forms::Padding(0);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(113, 28);
				 this->button1->TabIndex = 0;
				 this->button1->Text = L"Запустить ";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->button2->AutoSize = true;
				 this->button2->Location = System::Drawing::Point(168, 9);
				 this->button2->Margin = System::Windows::Forms::Padding(0);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(113, 28);
				 this->button2->TabIndex = 1;
				 this->button2->Text = L"Убить всех";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
				 // 
				 // button3
				 // 
				 this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->button3->AutoSize = true;
				 this->button3->Location = System::Drawing::Point(90, 64);
				 this->button3->Margin = System::Windows::Forms::Padding(0);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(113, 28);
				 this->button3->TabIndex = 2;
				 this->button3->Text = L"Убить одного";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &MyForm::Button3_Click);
				 // 
				 // MyForm
				 // 
				 this->AcceptButton = this->button1;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(290, 101);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"MyForm";
				 this->ShowIcon = false;
				 this->Text = L"Это окно";
				 this->TopMost = true;
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion



	private:System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// порождаем дочерний процесс
		BOOL fSuccess = CreateProcess(NULL,
			"Calc",
			NULL, NULL, false, 0, NULL, NULL,
			&sinfo, &pi);

		vector.push_back(pi);
		
	}

	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {

		for each (PROCESS_INFORMATION pi in vector) {
			
			TerminateProcess(pi.hProcess, 0);
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
		}
		vector.clear();
		
	}

	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!vector.empty()) {
			
			TerminateProcess(vector[vector.size() - 1].hProcess, 0);
			CloseHandle(vector[vector.size() - 1].hThread);
			CloseHandle(vector[vector.size() - 1].hProcess);
			
			vector.pop_back();
		}
		
	}

	
};
}