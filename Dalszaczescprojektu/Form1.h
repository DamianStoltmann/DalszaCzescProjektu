#pragma once
#include <fstream>
namespace WindowsFormApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool czyTekstZmieniony = false;



	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: Form ^ czyZapisacZmianyForm;
	private: Form ^ znajdzSlowoForm;
	private: MemoryStream^ userInput;
	private: bool czyPlikStworzony = false;
	private: String^ nazwa_pliku;
	private: String^ tekst;
	private: System::Windows::Forms::ToolStripMenuItem^  plikToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  opcjeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  autorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zapiszToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zakoñczToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  znajdzS³owoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oAutorzeToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			userInput = gcnew MemoryStream;
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->plikToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zapiszToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zakoñczToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opcjeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->znajdzS³owoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->autorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oAutorzeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 45);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(820, 254);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::czyZmienilSieTekst);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->plikToolStripMenuItem,
					this->opcjeToolStripMenuItem, this->autorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(844, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// plikToolStripMenuItem
			// 
			this->plikToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->zapiszToolStripMenuItem,
					this->zakoñczToolStripMenuItem
			});
			this->plikToolStripMenuItem->Name = L"plikToolStripMenuItem";
			this->plikToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->plikToolStripMenuItem->Text = L"Plik";
			// 
			// zapiszToolStripMenuItem
			// 
			this->zapiszToolStripMenuItem->Name = L"zapiszToolStripMenuItem";
			this->zapiszToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->zapiszToolStripMenuItem->Text = L"Zapisz";
			this->zapiszToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zapiszToolStripMenuItem_Click);
			// 
			// zakoñczToolStripMenuItem
			// 
			this->zakoñczToolStripMenuItem->Name = L"zakoñczToolStripMenuItem";
			this->zakoñczToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->zakoñczToolStripMenuItem->Text = L"Zakoñcz";
			this->zakoñczToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::zakoñczToolStripMenuItem_Click);
			// 
			// opcjeToolStripMenuItem
			// 
			this->opcjeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->znajdzS³owoToolStripMenuItem });
			this->opcjeToolStripMenuItem->Name = L"opcjeToolStripMenuItem";
			this->opcjeToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->opcjeToolStripMenuItem->Text = L"Opcje";
			// 
			// znajdzS³owoToolStripMenuItem
			// 
			this->znajdzS³owoToolStripMenuItem->Name = L"znajdzS³owoToolStripMenuItem";
			this->znajdzS³owoToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->znajdzS³owoToolStripMenuItem->Text = L"Znajdz s³owo";
			this->znajdzS³owoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::znajdzSlowoToolStripMenuItem_Click);

			// 
			// autorToolStripMenuItem
			// 
			this->autorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->oAutorzeToolStripMenuItem });
			this->autorToolStripMenuItem->Name = L"autorToolStripMenuItem";
			this->autorToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			this->autorToolStripMenuItem->Text = L"Autor";
			// 
			// oAutorzeToolStripMenuItem
			// 
			this->oAutorzeToolStripMenuItem->Name = L"oAutorzeToolStripMenuItem";
			this->oAutorzeToolStripMenuItem->Size = System::Drawing::Size(125, 22);
			this->oAutorzeToolStripMenuItem->Text = L"O autorze";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 311);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void zakoñczToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (czyTekstZmieniony == false)
		{
			this->Close();
		}
		else
		{
			czyZapisacZmianyForm = gcnew Form();
			czyZapisacZmianyForm->Width = 400;
			czyZapisacZmianyForm->Height = 100;

			czyZapisacZmianyForm->Text = "Czy chcesz zapisaæ zmiany ?";

			Button^ takBtn = gcnew Button();
			takBtn->Location = Point(75, 30);
			takBtn->Text = "Tak";
			takBtn->Click += gcnew System::EventHandler(this, &Form1::takBtn_Click);

			Button^ nieBtn = gcnew Button();
			nieBtn->Location = Point(150, 30);
			nieBtn->Text = "Nie";
			nieBtn->Click += gcnew System::EventHandler(this, &Form1::nieBtn_Click);


			Button^ anulujBtn = gcnew Button();
			anulujBtn->Location = Point(225, 30);
			anulujBtn->Text = "Anuluj";
			anulujBtn->Click += gcnew System::EventHandler(this, &Form1::anulujBtn_Click);



			czyZapisacZmianyForm->Controls->Add(takBtn);
			czyZapisacZmianyForm->Controls->Add(nieBtn);
			czyZapisacZmianyForm->Controls->Add(anulujBtn);

			czyZapisacZmianyForm->ShowDialog();
		}

	}

	private: System::Void zapiszToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
		if (!czyPlikStworzony){
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			saveFileDialog1->ShowDialog();
			richTextBox1->SaveFile(saveFileDialog1->FileName, RichTextBoxStreamType::PlainText);
			nazwa_pliku = saveFileDialog1->FileName;
			czyPlikStworzony = true;
		}
		else{
			FileStream^ plik;
			plik = File::Open(nazwa_pliku, FileMode::Open);
			richTextBox1->SaveFile(userInput, RichTextBoxStreamType::PlainText);
			userInput->WriteByte(13);
			userInput->Position = 0;
			userInput->WriteTo(plik);
			plik->Close();
		}
	}
	private: System::Void czyZmienilSieTekst(System::Object^  sender, System::EventArgs^  e) {
		czyTekstZmieniony = true;

	}
	private: System::Void znajdzSlowoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		tekst = richTextBox1->Text;
		znajdzSlowoForm = gcnew Form();
		znajdzSlowoForm->Width = 300;
		znajdzSlowoForm->Height = 200;

		znajdzSlowoForm->Text = "Wyszukaj w teœcie wzorzec";
		TextBox^ wpiszSlowo = gcnew TextBox();
		wpiszSlowo->Location = Point(140, 40);
		Button^ szukajBtn = gcnew Button();
		szukajBtn->Location = Point(155, 70);
		Label^ napis = gcnew Label();
		napis->Text = "S³owo wyst¹pi³o:";
		napis->Location = Point(20, 100);
		szukajBtn->Text = "Szukaj";
		szukajBtn->Click += gcnew System::EventHandler(this, &Form1::szukajBtn_Click);

		znajdzSlowoForm->Controls->Add(napis);
		znajdzSlowoForm->Controls->Add(wpiszSlowo);
		znajdzSlowoForm->Controls->Add(szukajBtn);
		znajdzSlowoForm->Show();

	}
	private: System::Void nieBtn_Click(System::Object^  sender, System::EventArgs^  e){
		this->Close();
	}

	private: System::Void anulujBtn_Click(System::Object^  sender, System::EventArgs^  e){
		czyZapisacZmianyForm->Close();
	}

			 void MarshalString(String ^ s, string& os) {

				 using namespace Runtime::InteropServices;
				 const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
			 }

	private: System::Void takBtn_Click(System::Object^  sender, System::EventArgs^  e){

		if (!czyPlikStworzony){
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
			saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			saveFileDialog1->ShowDialog();
			richTextBox1->SaveFile(saveFileDialog1->FileName, RichTextBoxStreamType::PlainText);
			nazwa_pliku = saveFileDialog1->FileName;
			czyPlikStworzony = true;
			Close();
		}
		else{
			FileStream^ plik;
			plik = File::Open(nazwa_pliku, FileMode::Open);
			richTextBox1->SaveFile(userInput, RichTextBoxStreamType::PlainText);
			userInput->WriteByte(13);
			userInput->Position = 0;
			userInput->WriteTo(plik);
			plik->Close();
			Close();
		}

	}

	private: System::Void szukajBtn_Click(System::Object^  sender, System::EventArgs^  e){
		String^ s;
		String^ p;
		int length_ = tekst->Length;
		array<Int64>^ KMPNext = gcnew array<Int64>(length_ + 10);
		Int64 b, pp, ile = 0;
		int i;
		p = znajdzSlowoForm->Controls[1]->Text;
		s = tekst;
		KMPNext[0] = b = -1;
		for (i = 1; i <= p->Length; i++)
		{
			while ((b > -1) && (p[b] != p[i - 1])) b = KMPNext[b];
			++b;
			if ((i == p->Length) || (p[i] != p[b])) KMPNext[i] = b;
			else                           KMPNext[i] = KMPNext[b];
		}

		pp = b = 0;
		for (i = 0; i < length_; i++)
		{
			while ((b > -1) && (p[b] != s[i])) b = KMPNext[b];
			if (++b == p->Length)
			{
				while (pp < i - b + 1)
				{
					pp++;
				}
				pp++;
				ile++;
				b = KMPNext[b];
			}
		}
		znajdzSlowoForm->Controls[0]->Text += ile + " razy.";

	}
	};
}