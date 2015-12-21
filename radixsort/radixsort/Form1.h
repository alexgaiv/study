#pragma once

#include <math.h>
#include <cstdlib>
#include <vcclr.h>
#include <time.h>
#include "tqueue.h"

namespace radixsort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			init = false;
			srand(time((time_t *)0));
			InitializeComponent();
			arr = new int [arr_size];
			qs = new TQueue<int>[10];
		}
	private:
		int *arr;
		static const int arr_size = 10;
		int maxDigits, curDigit;
		bool init;
		TQueue<int> *qs;

		String ^JoinArr() {
			String ^s = "";
			for (int i = 0; i < arr_size; i++) {
				s += arr[i].ToString() + " ";
			}
			return s;
		}

		void RadixSort()
		{
			InitSort();
			for (curDigit = 0; curDigit < maxDigits; curDigit++)
				SortStep();
		}

		void InitSort()
		{
			int max = 0;
			for (int i = 0; i < arr_size; i++)
				if (arr[i] > max) max = arr[i];

			maxDigits = 0;
			while (max) {
				maxDigits++;
				max /= 10;
			}

			dataGridView1->Rows->Clear();
			for (int i = 0; i < maxDigits; i++) {
				array<String ^> ^row = { "", "", "", "", "", "", "", "", "", "" };
				dataGridView1->Rows->Add(row);
			}
			init = true;
		}
		

		void SortStep()
		{
			for (int i = 0; i < arr_size; i++) {
				int d = (arr[i] / (int)pow(10.0, curDigit)) % 10;
				qs[d].Push(arr[i]);
			}

			UpdateGrid();

			int k = 0;
			for (int i = 0; i < 10; i++) {
				while (!qs[i].IsEmpty()) {
					arr[k++] = qs[i].Pop();
				}
			}
		}

		void UpdateGrid()
		{
			for (int i = 0; i < maxDigits; i++) {
				for (int j = 0; j < 10; j++) {
					int free = maxDigits - 1;
					for (int k = 0; k < maxDigits - 1; i++) {
						if (dataGridView1->Rows[i]->Cells[j]->Value == nullptr ||
							dataGridView1->Rows[i]->Cells[j]->Value->ToString() = "")
						{
							free = k;
						}
					}

					if (!qs[i].IsEmpty())
						dataGridView1->Rows[i]->Cells[free]->Value = qs[i].Pop().ToString();
					else dataGridView1->Rows[i]->Cells[free]->Value = "";
				}
			}
		}

	protected:
		~Form1()
		{
			delete [] arr;
			delete [] qs;
			if (components)
				delete components;
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private: System::Windows::Forms::DataGridView^  dataGridView1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::TextBox^  textBox2;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Label^  label3;

		private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(459, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Array:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(73, 54);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(459, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Sorted:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(538, 17);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Randomize";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(538, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Step";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Queues:";
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(538, 52);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Sort";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {this->Column1, 
				this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9, this->Column10});
			this->dataGridView1->Location = System::Drawing::Point(29, 132);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(503, 230);
			this->dataGridView1->TabIndex = 8;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"0";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"1";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"2";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 50;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"3";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 50;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"4";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 50;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"5";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 50;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"6";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 50;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"7";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 50;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"8";
			this->Column9->Name = L"Column9";
			this->Column9->ReadOnly = true;
			this->Column9->Width = 50;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"9";
			this->Column10->Name = L"Column10";
			this->Column10->ReadOnly = true;
			this->Column10->Width = 50;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 381);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for (int i = 0; i < arr_size; i++)
			arr[i] = rand() % 10000;
		textBox1->Text = JoinArr();
		button2->Enabled = true;
		button3->Enabled = true;
		init = false;
		curDigit = 0;
	}
	void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		RadixSort();
		textBox2->Text = JoinArr();
	}
	void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!init) InitSort();
		if (curDigit++ < maxDigits) {
			SortStep();
			textBox2->Text = JoinArr();
		}
	}
};
}
