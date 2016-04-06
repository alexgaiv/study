#pragma once

#include "drawing.h"

namespace plex {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			PointNode p;
		}

	protected:
		~MyForm()
		{
			if (components) {
				delete components;
			}
		}

	private:
#pragma region Windows Form Designer generated code
		System::ComponentModel::Container ^components;
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(679, 418);
			this->Name = L"MyForm";
			this->Text = L"Paint, sir";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion


		void MyForm_MouseDown(Object^ sender, MouseEventArgs^  e)
		{

		}

		void MyForm_Paint(Object^ sender, PaintEventArgs^  e)
		{
			PointNode p1(100, 100), p2(50, 200);

			LineNode l(&p1, &p2);
			l.Draw(e->Graphics);

			ArcNode arc(&p1, 30, 0, 90);
			arc.Draw(e->Graphics);
		}
	};
}
