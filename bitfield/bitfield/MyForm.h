#pragma once

#include <vcclr.h>
#include "tset.h"

namespace bitfield {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			set1 = new TSet;
			set2 = new TSet;
		}

	protected:
		~MyForm()
		{
			if (components) delete components;
			delete set1;
			delete set2;
		}
	private:
		 TSet *set1, *set2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_usize;
	private: System::Windows::Forms::Button^  button_ok;
	private: System::Windows::Forms::TextBox^  textBox_el1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox_el2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button_and;
	private: System::Windows::Forms::Button^  button_not;
	private: System::Windows::Forms::Button^  button_or;
	private: System::Windows::Forms::TextBox^  textBox_result;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox_new;
	private: System::Windows::Forms::Button^  button_add;
	private: System::Windows::Forms::Button^  button_del;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_usize = (gcnew System::Windows::Forms::TextBox());
			this->button_ok = (gcnew System::Windows::Forms::Button());
			this->textBox_el1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_el2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_and = (gcnew System::Windows::Forms::Button());
			this->button_not = (gcnew System::Windows::Forms::Button());
			this->button_or = (gcnew System::Windows::Forms::Button());
			this->textBox_result = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_new = (gcnew System::Windows::Forms::TextBox());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_del = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Size of set:";
			// 
			// textBox_usize
			// 
			this->textBox_usize->Location = System::Drawing::Point(101, 19);
			this->textBox_usize->MaxLength = 5;
			this->textBox_usize->Name = L"textBox_usize";
			this->textBox_usize->Size = System::Drawing::Size(49, 20);
			this->textBox_usize->TabIndex = 2;
			this->textBox_usize->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_usize_KeyPress);
			// 
			// button_ok
			// 
			this->button_ok->Cursor = System::Windows::Forms::Cursors::Default;
			this->button_ok->Location = System::Drawing::Point(156, 17);
			this->button_ok->Name = L"button_ok";
			this->button_ok->Size = System::Drawing::Size(75, 23);
			this->button_ok->TabIndex = 3;
			this->button_ok->Text = L"OK";
			this->button_ok->UseVisualStyleBackColor = true;
			this->button_ok->Click += gcnew System::EventHandler(this, &MyForm::button_ok_Click);
			// 
			// textBox_el1
			// 
			this->textBox_el1->Enabled = false;
			this->textBox_el1->Location = System::Drawing::Point(101, 55);
			this->textBox_el1->Name = L"textBox_el1";
			this->textBox_el1->Size = System::Drawing::Size(130, 20);
			this->textBox_el1->TabIndex = 4;
			this->textBox_el1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_el1_KeyPress);
			this->textBox_el1->Leave += gcnew System::EventHandler(this, &MyForm::textBox_el1_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Enabled = false;
			this->label2->Location = System::Drawing::Point(26, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Set #1:";
			// 
			// textBox_el2
			// 
			this->textBox_el2->Enabled = false;
			this->textBox_el2->Location = System::Drawing::Point(101, 90);
			this->textBox_el2->Name = L"textBox_el2";
			this->textBox_el2->Size = System::Drawing::Size(130, 20);
			this->textBox_el2->TabIndex = 6;
			this->textBox_el2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_el2_KeyPress);
			this->textBox_el2->Leave += gcnew System::EventHandler(this, &MyForm::textBox_el2_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Enabled = false;
			this->label3->Location = System::Drawing::Point(26, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Set #2:";
			// 
			// button_and
			// 
			this->button_and->Enabled = false;
			this->button_and->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button_and->Location = System::Drawing::Point(101, 120);
			this->button_and->Name = L"button_and";
			this->button_and->Size = System::Drawing::Size(39, 35);
			this->button_and->TabIndex = 8;
			this->button_and->Text = L"&&";
			this->button_and->UseVisualStyleBackColor = true;
			this->button_and->Click += gcnew System::EventHandler(this, &MyForm::button_and_Click);
			// 
			// button_not
			// 
			this->button_not->Enabled = false;
			this->button_not->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button_not->Location = System::Drawing::Point(192, 120);
			this->button_not->Name = L"button_not";
			this->button_not->Size = System::Drawing::Size(39, 35);
			this->button_not->TabIndex = 9;
			this->button_not->Text = L"~";
			this->button_not->UseVisualStyleBackColor = true;
			this->button_not->Click += gcnew System::EventHandler(this, &MyForm::button_not_Click);
			// 
			// button_or
			// 
			this->button_or->Enabled = false;
			this->button_or->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button_or->Location = System::Drawing::Point(147, 120);
			this->button_or->Name = L"button_or";
			this->button_or->Size = System::Drawing::Size(38, 35);
			this->button_or->TabIndex = 10;
			this->button_or->Text = L"|";
			this->button_or->UseVisualStyleBackColor = true;
			this->button_or->Click += gcnew System::EventHandler(this, &MyForm::button_or_Click);
			// 
			// textBox_result
			// 
			this->textBox_result->Location = System::Drawing::Point(101, 164);
			this->textBox_result->Name = L"textBox_result";
			this->textBox_result->ReadOnly = true;
			this->textBox_result->Size = System::Drawing::Size(472, 20);
			this->textBox_result->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Enabled = false;
			this->label4->Location = System::Drawing::Point(295, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"New element:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 167);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Result:";
			// 
			// textBox_new
			// 
			this->textBox_new->Enabled = false;
			this->textBox_new->Location = System::Drawing::Point(373, 80);
			this->textBox_new->Name = L"textBox_new";
			this->textBox_new->Size = System::Drawing::Size(49, 20);
			this->textBox_new->TabIndex = 15;
			this->textBox_new->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_new_KeyPress);
			this->textBox_new->Leave += gcnew System::EventHandler(this, &MyForm::textBox_new_Leave);
			// 
			// button_add
			// 
			this->button_add->Enabled = false;
			this->button_add->Location = System::Drawing::Point(438, 61);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(135, 23);
			this->button_add->TabIndex = 16;
			this->button_add->Text = L"Add To Set #1";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_del
			// 
			this->button_del->Enabled = false;
			this->button_del->Location = System::Drawing::Point(438, 90);
			this->button_del->Name = L"button_del";
			this->button_del->Size = System::Drawing::Size(135, 23);
			this->button_del->TabIndex = 17;
			this->button_del->Text = L"Delete From Set #1";
			this->button_del->UseVisualStyleBackColor = true;
			this->button_del->Click += gcnew System::EventHandler(this, &MyForm::button_del_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 198);
			this->Controls->Add(this->button_del);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->textBox_new);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox_result);
			this->Controls->Add(this->button_or);
			this->Controls->Add(this->button_not);
			this->Controls->Add(this->button_and);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_el2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_el1);
			this->Controls->Add(this->button_ok);
			this->Controls->Add(this->textBox_usize);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Bit Field Class Testing";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	System::Void textBox_usize_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
			e->Handled = true;
	}
	System::Void button_ok_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int size = 0;
		if (!Int32::TryParse(textBox_usize->Text, size) && size != 0)
			return;

		for (int i = 0; i < Controls->Count; i++)
			Controls[i]->Enabled = true;

		textBox_el1->Text = "";
		textBox_el2->Text = "";
		textBox_result->Text = "";
		textBox_new->Text = "";
		
		if (set1) {
			delete set1;
			set1 = 0;
		}
		if (set2) {
			delete set2;
			set2 = 0;
		}
		set1 = new TSet(size);
		set2 = new TSet(size);
	}

	System::Void textBox_el1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && e->KeyChar != ' ')
			e->Handled = true;
	}

	System::Void textBox_el2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) && e->KeyChar != ' ')
			e->Handled = true;
	}

	System::Void textBox_new_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
			e->Handled = true;
	}

	System::Void textBox_el1_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_el1->Text->Length == 0) return;
		if (!set1->FromString(textBox_el1->Text))
			textBox_el1->Text = "";
	}

	System::Void textBox_el2_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_el2->Text->Length == 0) return;
		if (!set2->FromString(textBox_el2->Text))
			textBox_el2->Text = "";
	}

	System::Void textBox_new_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_new->Text->Length == 0) return;
		int index = Convert::ToInt32(textBox_new->Text);
		if (index >= set1->GetSize())
			textBox_new->Text = "";
			
	}

	System::Void button_and_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_el1->Text->Length != 0 && textBox_el2->Text->Length != 0)
			textBox_result->Text = (*set1 * *set2).ToString();
	}

	System::Void button_or_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_el1->Text->Length != 0 && textBox_el2->Text->Length != 0)
			textBox_result->Text = (*set1 + *set2).ToString();
	}

	System::Void button_not_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_el1->Text->Length != 0)
			textBox_result->Text = (-*set1).ToString();
	}

	System::Void button_add_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_new->Text->Length == 0) return;
		int index = Convert::ToInt32(textBox_new->Text);
		set1->AddElem(index);

		String ^s = set1->ToString();
		textBox_result->Text = s;
		textBox_el1->Text = s;
	}
	System::Void button_del_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBox_new->Text->Length == 0) return;
		int index = Convert::ToInt32(textBox_new->Text);
		set1->DelElem(index);

		String ^s = set1->ToString();
		textBox_result->Text = s;
		textBox_el1->Text = s;
	}
};
}
