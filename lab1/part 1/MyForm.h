#pragma once
#include <windows.h>
#include <shellapi.h>

namespace Project1
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

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

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->button1 = (gcnew System::Windows::Forms::Button());
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
				 // MyForm
				 // 
				 this->AcceptButton = this->button1;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(120, 101);
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
		
		
			
			String lol	
			LPCTSTR Path = (LPCTSTR)lol.constData();
			ShellExecute(NULL, NULL, Path, NULL, NULL, SW_RESTORE);
			int i = GetLastError();
			if (i > 0)
			{
				wchar_t* intStr = new wchar_t;
				_itow(i, intStr, 10);
				wchar_t* buff = new wchar_t;
				FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, i, 0, buff, someBuff, NULL);
				lol = QString::fromLocal8Bit("Код ошибки ") + QString::fromWCharArray(intStr) +
					" (" + QString::fromWCharArray(buff) + ")";
				ui.PathLineEdit->setText(lol);
			}
		

	}




	};
}