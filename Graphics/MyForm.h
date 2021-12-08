#pragma once
#include "..\Queue\TQueue.h"

namespace VisualQueue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		TQueue<int>* pQueue;
		
		int MaxSize, Size;
		double p, q;
		int PopCount, PushCount;
		
		int CenterX, CenterY;
		int Width, Height;

		Graphics^ gr;
		Random^ rnd1;
		Pen^ BlackPen;
		Pen^ WhitePen;

		bool isStartInProgress;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ MaxLengthBox;
	private: System::Windows::Forms::TextBox^ LengthBox;

	private: System::Windows::Forms::TextBox^ ProbabilityOfPushBox;
	private: System::Windows::Forms::TextBox^ ProbabilityOfPopBox;
	private: System::Windows::Forms::TextBox^ NumOfPushBox;
	private: System::Windows::Forms::TextBox^ NumOfPopBox;

	public:
		MyForm(void)
		{
			InitializeComponent();

			gr = CreateGraphics();
			rnd1 = gcnew Random();

			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;

			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;

			CenterX = 200;
			CenterY = 240;
			Width = Height = 200;

			PopCount = PushCount = 0;

			isStartInProgress = false;
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ startButton;
	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ stopButton;


	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->stopButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->MaxLengthBox = (gcnew System::Windows::Forms::TextBox());
			this->LengthBox = (gcnew System::Windows::Forms::TextBox());
			this->ProbabilityOfPushBox = (gcnew System::Windows::Forms::TextBox());
			this->ProbabilityOfPopBox = (gcnew System::Windows::Forms::TextBox());
			this->NumOfPushBox = (gcnew System::Windows::Forms::TextBox());
			this->NumOfPopBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(426, 95);
			this->startButton->Margin = System::Windows::Forms::Padding(4);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(132, 28);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Старт";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MyForm::startButton_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// stopButton
			// 
			this->stopButton->Location = System::Drawing::Point(426, 131);
			this->stopButton->Margin = System::Windows::Forms::Padding(4);
			this->stopButton->Name = L"stopButton";
			this->stopButton->Size = System::Drawing::Size(132, 28);
			this->stopButton->TabIndex = 1;
			this->stopButton->Text = L"Стоп";
			this->stopButton->UseVisualStyleBackColor = true;
			this->stopButton->Click += gcnew System::EventHandler(this, &MyForm::stopButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 34);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Максимальная длина очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(50, 66);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(175, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Исходная длина очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(47, 98);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Вероятность добавления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(48, 127);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(175, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Вероятность извлечения";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(71, 159);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Добавлено в очередь";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(66, 191);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(159, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Извлечено из очереди";
			// 
			// MaxLengthBox
			// 
			this->MaxLengthBox->Location = System::Drawing::Point(235, 31);
			this->MaxLengthBox->Margin = System::Windows::Forms::Padding(4);
			this->MaxLengthBox->Name = L"MaxLengthBox";
			this->MaxLengthBox->Size = System::Drawing::Size(156, 23);
			this->MaxLengthBox->TabIndex = 8;
			// 
			// LengthBox
			// 
			this->LengthBox->Location = System::Drawing::Point(235, 63);
			this->LengthBox->Margin = System::Windows::Forms::Padding(4);
			this->LengthBox->Name = L"LengthBox";
			this->LengthBox->Size = System::Drawing::Size(156, 23);
			this->LengthBox->TabIndex = 9;
			// 
			// ProbabilityOfPushBox
			// 
			this->ProbabilityOfPushBox->Location = System::Drawing::Point(235, 95);
			this->ProbabilityOfPushBox->Margin = System::Windows::Forms::Padding(4);
			this->ProbabilityOfPushBox->Name = L"ProbabilityOfPushBox";
			this->ProbabilityOfPushBox->Size = System::Drawing::Size(156, 23);
			this->ProbabilityOfPushBox->TabIndex = 10;
			// 
			// ProbabilityOfPopBox
			// 
			this->ProbabilityOfPopBox->Location = System::Drawing::Point(235, 127);
			this->ProbabilityOfPopBox->Margin = System::Windows::Forms::Padding(4);
			this->ProbabilityOfPopBox->Name = L"ProbabilityOfPopBox";
			this->ProbabilityOfPopBox->Size = System::Drawing::Size(156, 23);
			this->ProbabilityOfPopBox->TabIndex = 11;
			// 
			// NumOfPushBox
			// 
			this->NumOfPushBox->Enabled = false;
			this->NumOfPushBox->Location = System::Drawing::Point(235, 159);
			this->NumOfPushBox->Margin = System::Windows::Forms::Padding(4);
			this->NumOfPushBox->Name = L"NumOfPushBox";
			this->NumOfPushBox->Size = System::Drawing::Size(156, 23);
			this->NumOfPushBox->TabIndex = 12;
			// 
			// NumOfPopBox
			// 
			this->NumOfPopBox->Enabled = false;
			this->NumOfPopBox->Location = System::Drawing::Point(235, 191);
			this->NumOfPopBox->Margin = System::Windows::Forms::Padding(4);
			this->NumOfPopBox->Name = L"NumOfPopBox";
			this->NumOfPopBox->Size = System::Drawing::Size(156, 23);
			this->NumOfPopBox->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 472);
			this->Controls->Add(this->NumOfPopBox);
			this->Controls->Add(this->NumOfPushBox);
			this->Controls->Add(this->ProbabilityOfPopBox);
			this->Controls->Add(this->ProbabilityOfPushBox);
			this->Controls->Add(this->LengthBox);
			this->Controls->Add(this->MaxLengthBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->stopButton);
			this->Controls->Add(this->startButton);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(600, 510);
			this->MinimumSize = System::Drawing::Size(600, 510);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Visual queue";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isStartInProgress) {
			try {
				MaxSize = System::Convert::ToInt32(MaxLengthBox->Text);
				pQueue = new TQueue<int>(MaxSize);
				Size = System::Convert::ToInt32(LengthBox->Text);
				for (int i = 0; i < Size; ++i)
					pQueue->Push(1);
				p = System::Convert::ToDouble(ProbabilityOfPushBox->Text);
				q = System::Convert::ToDouble(ProbabilityOfPopBox->Text);
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}

			isStartInProgress = true;
			timer1->Enabled = true;
		}
		else
		{
			MessageBox::Show("Старт уже нажат");
			return;
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Стереть очередь
		Clean();
		//Обновить состояние очереди
		try {
			if (rnd1->NextDouble() < p) {
				pQueue->Push(1);
				PushCount++;
			}
			if (rnd1->NextDouble() < q) {
				pQueue->Pop();
				PopCount++;
			}
		}
		catch (Exception^ ex) {
			timer1->Enabled = false;
			MessageBox::Show(ex->Message);			
		}
		//Нарисовать очередь
		DrawQueue();
		//Обновить статистику
		NumOfPushBox->Text = Convert::ToString(PushCount);
		NumOfPopBox->Text = Convert::ToString(PopCount);
	}

	private: System::Void stopButton_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		isStartInProgress = false;
		Clear();

		PushCount = 0;
		PopCount = 0;

		NumOfPushBox->Text = "";
		NumOfPopBox->Text = "";

		this->Refresh();
	}
	private: void DrawQueue()
	{
		//Вычисляем стартовый угол
		int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
		int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();

		//нарисовать дугу от tail до head
		gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
	}

	private: void Clean()
	{
		//Вычисляем стартовый угол
		int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
		int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();

		//нарисовать дугу от tail до head
		gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
	}	

	private: void Clear()
	{
		gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, 360, 360);
	}
};
}
