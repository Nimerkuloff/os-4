#pragma once
#include <windows.h>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	STARTUPINFO          sinfo;
	PROCESS_INFORMATION  pinfo;
	HANDLE hnd;
	bool wasButton1Pressed = 0;
	bool itIsDead = 0;

	public ref class MyForm : public System::Windows::Forms::Form {
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
	protected:

	protected:

	private: System::Windows::Forms::Button^ button2;
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
				 this->button1->Size = System::Drawing::Size(93, 28);
				 this->button1->TabIndex = 0;
				 this->button1->Text = L"Запустить";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
				 // 
				 // button2
				 // 
				 this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->button2->AutoSize = true;
				 this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				 this->button2->Location = System::Drawing::Point(12, 58);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(93, 30);
				 this->button2->TabIndex = 1;
				 this->button2->Text = L"Не запустить";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
				 // 
				 // MyForm
				 // 
				 this->AcceptButton = this->button1;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->CancelButton = this->button2;
				 this->ClientSize = System::Drawing::Size(120, 101);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"MyForm";
				 this->ShowIcon = false;
				 this->Text = L"Это окно";
				 this->TopMost = true;
				 this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

			

	private:System::Void Button1_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		button1->Enabled = false;
		button2->Enabled = true;

		CreateProcessStuff();

		CreateProcess(
			NULL,
			"C:\\Program Files\\Microsoft Office\\Office16\\WINWORD.EXE /n C:\\Users\\nimerkuloff\\Downloads\\file.docx",
			NULL, NULL, false, 0,
			NULL, NULL, &sinfo, &pinfo
		);

		wasButton1Pressed = true;
	}
			

	private: System::Void Button2_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		itIsDead = true;
		DWORD pid = pinfo.dwProcessId;
		KillProcessById(pid);
		CloseHandle(hnd);
		CloseHandle(pinfo.hProcess);
		button1->Enabled = true;
		button2->Enabled = false;
		itIsDead = true;

	}
	private: System::Void MyForm_Load(System::Object ^ sender, System::EventArgs ^ e) {}
	private: System::Void MyForm_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e) {
		if (wasButton1Pressed && !itIsDead) {
			DWORD pid = pinfo.dwProcessId;
			KillProcessById(pid);
			CloseHandle(hnd);
			CloseHandle(pinfo.hProcess);
		}
	}



	void KillProcessById(DWORD pid) {
		hnd = OpenProcess(SYNCHRONIZE | PROCESS_TERMINATE, TRUE, pid);
		TerminateProcess(hnd, 0);
	}
	void CreateProcessStuff()
	{
		memset(&pinfo, 0, sizeof(pinfo));
		memset(&sinfo, 0, sizeof(sinfo));
		sinfo.cb = sizeof(sinfo);
	}
	};
}