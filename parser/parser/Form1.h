#pragma once

#include "parser.h"
#include <msclr\marshal_cppstd.h>

namespace parser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			parser = new Parser("");
		}
	private: System::Windows::Forms::TextBox^  textBox_rpn;
	public: 

	private:
		Parser *parser;

		string Sys2Std(String ^s) {
			return msclr::interop::marshal_as<string>(s);
		}

		String ^Std2Sys(string s) {
			return gcnew String(s.c_str());
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
				delete parser;
			}
		}

#pragma region Windows Form Designer generated code
		System::ComponentModel::Container ^components;

		private: System::Windows::Forms::ToolStripStatusLabel^  status;
		private: System::Windows::Forms::DataGridView^  dataGridView_vars;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  NameColumn;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  ValueColumn;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TextBox^  textBox_expr;
		private: System::Windows::Forms::Button^  button1;

		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;
		private: System::Windows::Forms::StatusStrip^  statusStrip;
		private: System::Windows::Forms::Button^  button_eval;
		private: System::Windows::Forms::TextBox^  textBox_result;
		private: System::Windows::Forms::Label^  label4;

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_expr = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->status = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->button_eval = (gcnew System::Windows::Forms::Button());
			this->textBox_result = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView_vars = (gcnew System::Windows::Forms::DataGridView());
			this->NameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox_rpn = (gcnew System::Windows::Forms::TextBox());
			this->statusStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_vars))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Expression:";
			// 
			// textBox_expr
			// 
			this->textBox_expr->Location = System::Drawing::Point(16, 29);
			this->textBox_expr->Name = L"textBox_expr";
			this->textBox_expr->Size = System::Drawing::Size(492, 20);
			this->textBox_expr->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(515, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Reverse polish notation:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 109);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Variables:";
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->status});
			this->statusStrip->Location = System::Drawing::Point(0, 294);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(601, 22);
			this->statusStrip->SizingGrip = false;
			this->statusStrip->TabIndex = 7;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// status
			// 
			this->status->ForeColor = System::Drawing::Color::Red;
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(0, 17);
			// 
			// button_eval
			// 
			this->button_eval->Enabled = false;
			this->button_eval->Location = System::Drawing::Point(177, 135);
			this->button_eval->Name = L"button_eval";
			this->button_eval->Size = System::Drawing::Size(142, 27);
			this->button_eval->TabIndex = 9;
			this->button_eval->Text = L"Evaluate";
			this->button_eval->UseVisualStyleBackColor = true;
			this->button_eval->Click += gcnew System::EventHandler(this, &Form1::button_eval_Click);
			// 
			// textBox_result
			// 
			this->textBox_result->Location = System::Drawing::Point(222, 168);
			this->textBox_result->Name = L"textBox_result";
			this->textBox_result->ReadOnly = true;
			this->textBox_result->Size = System::Drawing::Size(97, 20);
			this->textBox_result->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(176, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Result:";
			// 
			// dataGridView_vars
			// 
			this->dataGridView_vars->AllowUserToAddRows = false;
			this->dataGridView_vars->AllowUserToDeleteRows = false;
			this->dataGridView_vars->AllowUserToResizeColumns = false;
			this->dataGridView_vars->AllowUserToResizeRows = false;
			this->dataGridView_vars->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView_vars->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_vars->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->NameColumn, 
				this->ValueColumn});
			this->dataGridView_vars->Enabled = false;
			this->dataGridView_vars->Location = System::Drawing::Point(16, 135);
			this->dataGridView_vars->MultiSelect = false;
			this->dataGridView_vars->Name = L"dataGridView_vars";
			this->dataGridView_vars->RowHeadersVisible = false;
			this->dataGridView_vars->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView_vars->ShowEditingIcon = false;
			this->dataGridView_vars->Size = System::Drawing::Size(142, 150);
			this->dataGridView_vars->TabIndex = 12;
			this->dataGridView_vars->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView_vars_CellEndEdit);
			// 
			// NameColumn
			// 
			this->NameColumn->Frozen = true;
			this->NameColumn->HeaderText = L"Name";
			this->NameColumn->Name = L"NameColumn";
			this->NameColumn->ReadOnly = true;
			this->NameColumn->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->NameColumn->Width = 70;
			// 
			// ValueColumn
			// 
			this->ValueColumn->Frozen = true;
			this->ValueColumn->HeaderText = L"Value";
			this->ValueColumn->Name = L"ValueColumn";
			this->ValueColumn->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->ValueColumn->Width = 70;
			// 
			// textBox_rpn
			// 
			this->textBox_rpn->Location = System::Drawing::Point(16, 77);
			this->textBox_rpn->Name = L"textBox_rpn";
			this->textBox_rpn->ReadOnly = true;
			this->textBox_rpn->Size = System::Drawing::Size(492, 20);
			this->textBox_rpn->TabIndex = 13;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(601, 316);
			this->Controls->Add(this->textBox_rpn);
			this->Controls->Add(this->dataGridView_vars);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox_result);
			this->Controls->Add(this->button_eval);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox_expr);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"Arithmetic Expression Parser";
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_vars))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		delete parser;
		parser = new Parser(Sys2Std(textBox_expr->Text));
		string err = parser->LastError();
		if (err == "") {
			button_eval->Enabled = true;
			status->Text = "";
			textBox_rpn->Text = Std2Sys(parser->GetPoliz());

			
			dataGridView_vars->Rows->Clear();
			dataGridView_vars->Enabled = true;

			TMap<double> *vars = parser->GetVarTable();
			for (int i = 0; i < vars->GetCount(); i++) {
				dataGridView_vars->Rows->Add(Std2Sys(vars->GetKeyAt(i)), "0");
			}
		}
		else {
			status->Text = Std2Sys("Error: " + err);
		}
	}

	void dataGridView_vars_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		DataGridViewCell ^c = dataGridView_vars->Rows[e->RowIndex]->Cells[e->ColumnIndex];
		double v = 0.0;
		if (!Double::TryParse(c->Value->ToString(), NumberStyles::Any, CultureInfo::InvariantCulture, v))
			c->Value = "0";
	}
	void button_eval_Click(System::Object^  sender, System::EventArgs^  e)
	{
		TMap<double> *vars = parser->GetVarTable();
		for (int i = 0; i < vars->GetCount(); i++)
		{
			String ^name = dataGridView_vars->Rows[i]->Cells[0]->Value->ToString();
			String ^value = dataGridView_vars->Rows[i]->Cells[1]->Value->ToString();
			double v = 0.0;
			Double::TryParse(value, NumberStyles::Any, CultureInfo::InvariantCulture, v);
			vars->SetValue(Sys2Std(name), v);
		}

		string err = parser->LastError();
		if (err == "")
			textBox_result->Text = parser->Evaluate().ToString();
		else {
			status->Text = Std2Sys("Error: " + err);
		}
	}
};
}

