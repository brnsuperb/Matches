#pragma once
#include "Level.h"
#include "Match.h"
#include <cstring>

namespace ClientApp {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static Match matches[32];		//наши спички
	static int matchIndex = 0;		//индекс в массиве спичек
	static bool move = false;		//Флаг - показывает, можно ли перемещать или нет
	static int movedIndex = 0;		//индекс перемещаемой спички
	static int LevelNumber = 0;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public: 

		
		
		static Bitmap ^ source;




























		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;



































	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(849, 520);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(318, 238);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(207, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(319, 323);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(207, 36);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(762, 485);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Меню";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(319, 281);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(207, 36);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Продолжить";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"label1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(849, 520);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра \"Спички\"";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Нажатие на кнопку "Выход"
				 this->Close();
			 }

			 //Рисуем одну спичку по передаваемому индексу
	private: void drawOneMatch(int index, Graphics ^ g){
					Rectangle rect;
					Bitmap ^ image;
					rect.Width = matches[index].getWidth();
					rect.Height = matches[index].getHeight();
					
					if (rect.Width < 81) image = gcnew Bitmap("match_up.png");
					else image = gcnew Bitmap("match_right.png");
					rect.X = matches[index].getX();
					rect.Y = matches[index].getY();
					matches[index].setFull(true);
					g->DrawImage(image, rect);
			 }
	private: void drawBWMatch(int index, Graphics ^ g){
				    Rectangle rect;
					Bitmap ^ image;
					rect.Width = matches[index].getWidth();
					rect.Height = matches[index].getHeight();
					
					if (rect.Width < 81) image = gcnew Bitmap("match_bw_up.png");
					else image = gcnew Bitmap("match_bw_right.png");
					rect.X = matches[index].getX();
					rect.Y = matches[index].getY();
					matches[index].setFull(false);
					g->DrawImage(image, rect);
			 }

	
	private: void drawLevelOne(){
				 LevelNumber = 1;
				 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
				 Graphics ^ g = Graphics::FromImage(bmp);
				 this->pictureBox1->Image = bmp;
				 
				 //цифра 6
				 drawOneMatch(0,g);
				 drawOneMatch(1,g);
				 drawOneMatch(2,g);
				 drawOneMatch(9,g);
				 drawOneMatch(10,g);
				 drawOneMatch(12,g);
				 //знак плюс
				 drawOneMatch(28,g);
				 drawOneMatch(29,g);
				 //цифра 2
				 drawOneMatch(3,g);
				 drawOneMatch(4,g);
				 drawOneMatch(5,g);
				 drawOneMatch(14,g);
				 drawOneMatch(15,g);
				 //цифра 5
				 drawOneMatch(6,g);
				 drawOneMatch(7,g);
				 drawOneMatch(8,g);
				 drawOneMatch(19,g);
				 drawOneMatch(20,g);
				 //Знак равно
				 drawOneMatch(30,g);
				 drawOneMatch(31,g);


				 for (int i = 0;i < 28;i++){
					 if (!matches[i].isFull()){
						 drawBWMatch(i,g);
					 }
				 }

				 this->label1->Text = "Уровень 1. Переложите две спички так, чтобы получилось верное равенство";
				 //Выводим текст
				 /*
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",16 );
				SolidBrush^ drawBrush = gcnew SolidBrush( Color::White );
				PointF drawPoint = PointF(15.0F,15.0F);
				g->DrawString("Уровень 1. Переложите две спички так, чтобы получилось верное равенство", drawFont, drawBrush, drawPoint);*/
			 }
			 private: void drawLevelTwo(){
				 LevelNumber = 2;
				 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
				 Graphics ^ g = Graphics::FromImage(bmp);
				 this->pictureBox1->Image = bmp;
				 for (int i = 0;i < 32;i++){
					 matches[i].setFull(false);
				 }

				 //цифра 5
				 drawOneMatch(0,g);
				 drawOneMatch(1,g);
				 drawOneMatch(2,g);
				 drawOneMatch(9,g);
				 drawOneMatch(12,g);
				 //знак плюс
				 drawOneMatch(28,g);
				 drawOneMatch(29,g);
				 //цифра 5
				 drawOneMatch(3,g);
				 drawOneMatch(4,g);
				 drawOneMatch(5,g);
				 drawOneMatch(13,g);
				 drawOneMatch(16,g);
				 //цифра 8
				 drawOneMatch(6,g);
				 drawOneMatch(7,g);
				 drawOneMatch(8,g);
				 drawOneMatch(17,g);
				 drawOneMatch(18,g);
				 drawOneMatch(19,g);
				 drawOneMatch(20,g);
				 
				 //Знак равно
				 drawOneMatch(30,g);
				 drawOneMatch(31,g);


				 for (int i = 0;i < 28;i++){
					 if (!matches[i].isFull()){
						 drawBWMatch(i,g);
					 }
				 }
				 this->label1->Text = "Уровень 2. Переложите одну спичку так, чтобы получилось верное равенство";
				 //Выводим текст
				 /*
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",16 );
				SolidBrush^ drawBrush = gcnew SolidBrush( Color::White );
				PointF drawPoint = PointF(15.0F,15.0F);
				g->DrawString("Уровень 1. Переложите две спички так, чтобы получилось верное равенство", drawFont, drawBrush, drawPoint);*/
			 }

	private: void drawLevelThree(){
				 LevelNumber = 3;
				 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
				 Graphics ^ g = Graphics::FromImage(bmp);
				 this->pictureBox1->Image = bmp;
				 for (int i = 0;i < 32;i++){
					 matches[i].setFull(false);
				 }
				 //цифра 9
				 drawOneMatch(0,g);
				 drawOneMatch(1,g);
				 drawOneMatch(2,g);
				 drawOneMatch(9,g);
				 drawOneMatch(12,g);
				 drawOneMatch(11,g);
				 //знак плюс
				 drawOneMatch(28,g);
				 drawOneMatch(29,g);
				 //цифра 5
				 drawOneMatch(3,g);
				 drawOneMatch(4,g);
				 drawOneMatch(5,g);
				 drawOneMatch(13,g);
				 drawOneMatch(16,g);
				 //цифра 0
				 drawOneMatch(6,g);
				 drawOneMatch(8,g);
				 drawOneMatch(17,g);
				 drawOneMatch(18,g);
				 drawOneMatch(19,g);
				 drawOneMatch(20,g);
				 
				 //Знак равно
				 drawOneMatch(30,g);
				 drawOneMatch(31,g);


				 for (int i = 0;i < 28;i++){
					 if (!matches[i].isFull()){
						 drawBWMatch(i,g);
					 }
				 }
				 this->label1->Text = "Уровень 3. Переложите одну спичку так, чтобы получилось верное равенство";

				 //Выводим текст
				 /*
				System::Drawing::Font^ drawFont = gcnew System::Drawing::Font( "Arial",16 );
				SolidBrush^ drawBrush = gcnew SolidBrush( Color::White );
				PointF drawPoint = PointF(15.0F,15.0F);
				g->DrawString("Уровень 1. Переложите две спички так, чтобы получилось верное равенство", drawFont, drawBrush, drawPoint);*/
			 }

	private: void update(){
				 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
				 Graphics ^ g = Graphics::FromImage(bmp);
				 this->pictureBox1->Image = bmp;
				 //знак плюс
				 //drawOneMatch(28,g);
				 //drawOneMatch(29,g);
				 //Знак равно
				 drawOneMatch(30,g);
				 drawOneMatch(31,g);
				 for (int i = 0;i < 32;i++){
					 if (matches[i].isFull()){
						 drawOneMatch(i,g);
					 }
					 else{
						 drawBWMatch(i,g);
					 }
				 }
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Нажатие на кнопку "Старт"
				 this->button1->Visible = false;	//скрываем кнопку "Старт"
				 this->button2->Visible = false;	//скрываем кнопку "Выход"
				 this->button3->Visible = true;		//показываем кнопку "Меню"
				 this->button4->Visible = false;	//скрываем кнопку "Продолжить"
				 InitMatches();
				 drawLevelOne();
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Нажатие на кнопку "Меню"
				
				 this->button1->Visible = true;			//показываем кнопку "Старт"
				 this->button2->Visible = true;			//показываем кнопку "Выход"
				 this->button3->Visible = false;		//скрываем кнопку "Меню"
				 this->button4->Visible = true;			//показываем кнопку "Продолжить"
				 
			 }

	private: void StartDraw(){
				 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
				 Graphics ^ g = Graphics::FromImage(bmp);
				 this->pictureBox1->Image = bmp;
				
				Bitmap ^ image = gcnew Bitmap("match_bw_right.png");
				Rectangle rect;
				rect.Width = 81;
				rect.Height = 13;
				rect.X = 375;
				rect.Y = 150;
				g->DrawImage(image, rect);
				image = gcnew Bitmap("match_bw_left.png");
				rect.Width = 81;
				rect.Height = 13;
				rect.X = 375;
				rect.Y = 50;
				g->DrawImage(image, rect);
				image = gcnew Bitmap("match.png");
				rect.Width = 13;
				rect.Height = 81;
				rect.X = 360;
				rect.Y = 66;
				g->DrawImage(image, rect);
				image = gcnew Bitmap("match.png");
				rect.Width = 13;
				rect.Height = 81;
				rect.X = 457;
				rect.Y = 66;
				g->DrawImage(image, rect);
			 }

	//Функция начальной отрисовки полотна
	private: void InitMatches(){
				 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
				 Graphics ^ g = Graphics::FromImage(bmp);
				 this->pictureBox1->Image = bmp;
				 int y = 158;
				 int x = 72;
				 //рисуем горизонтальные спички
				 for (int k = 0;k < 3;k++){
					 y = 158;
					 for (int i = 0;i < 3;i++){
						 Bitmap ^ image1 = gcnew Bitmap("match_bw_right.png");
						 Rectangle rect;
						 rect.Width = 81;
						 rect.Height = 13;
						 rect.X = x;
						 rect.Y = y;
						 matches[matchIndex].setCoord(x,y);
						 matches[matchIndex].setRect(81, 13);
						 matchIndex++;
						 y += 94;
						 g->DrawImage(image1, rect);
					 }
					 x += 244;
				 }

				 //рисуем вертикальные спички
				 x = 54;
				 y = 174;
				 for (int i = 0;i < 3;i++){
					 Bitmap ^ image1 = gcnew Bitmap("match_bw_up.png");
						 Rectangle rect;
						 rect.Width = 13;
						 rect.Height = 81;
						 rect.X = x;
						 rect.Y = y;
						 matches[matchIndex].setCoord(x,y);
						 matches[matchIndex].setRect(13, 81);
						 matchIndex++;
						 g->DrawImage(image1, rect);
						 rect.X = x;
						 rect.Y = y + 92;
						 matches[matchIndex].setCoord(x,y + 92);
						 matches[matchIndex].setRect(13, 81);
						 matchIndex++;
						 g->DrawImage(image1, rect);
						 rect.X = x + 104;
						 rect.Y = y;
						 matches[matchIndex].setCoord(x + 104,y);
						 matches[matchIndex].setRect(13, 81);
						 matchIndex++;
						 g->DrawImage(image1, rect);
						 rect.X = x + 104;
						 rect.Y = y + 92;
						 matches[matchIndex].setCoord(x + 104,y + 92);
						 matches[matchIndex].setRect(13, 81);
						 matchIndex++;
						 g->DrawImage(image1, rect);
						 x += 244;
				 }
				 
				 //рисуем вторую цифру после знака "="
				 x = 695;
				 y = 158;
				 for (int i = 0;i < 3;i++){
						 Bitmap ^ image1 = gcnew Bitmap("match_bw_right.png");
						 Rectangle rect;
						 rect.Width = 81;
						 rect.Height = 13;
						 rect.X = x;
						 rect.Y = y;
						 matches[matchIndex].setCoord(x,y);
						 matches[matchIndex].setRect(81, 13);
						 matchIndex++;
						 y += 94;
						 g->DrawImage(image1, rect);
					 }
				 x = 677;
				 y = 174;
				 Bitmap ^ image = gcnew Bitmap("match_bw_up.png");
				Rectangle rect;
				rect.Width = 13;
				rect.Height = 81;
				
				rect.X = x;
				rect.Y = y;
				matches[matchIndex].setCoord(x,y);
				matches[matchIndex].setRect(13, 81);
				matchIndex++;
				g->DrawImage(image, rect);
				rect.X = x;
				rect.Y = y + 92;
				matches[matchIndex].setCoord(x,y + 92);
				matches[matchIndex].setRect(13, 81);
				matchIndex++;
				g->DrawImage(image, rect);
				rect.X = x + 104;
				rect.Y = y;
				matches[matchIndex].setCoord(x + 104,y);
				matches[matchIndex].setRect(13, 81);
				matchIndex++;
				g->DrawImage(image, rect);
				rect.X = x + 104;
				rect.Y = y + 92;
				matches[matchIndex].setCoord(x + 104,y + 92);
				matches[matchIndex].setRect(13, 81);
				matchIndex++;
				g->DrawImage(image, rect);
				x += 244;


				//рисуем знак "+"

				image = gcnew Bitmap("match_bw_right.png");
				
				rect.Width = 81;
				rect.Height = 13;
				rect.X = 195;
				rect.Y = 252;
				matches[matchIndex].setCoord(195,252);
				matches[matchIndex].setRect(81, 13);
				matchIndex++;
				g->DrawImage(image, rect);
				image = gcnew Bitmap("match_bw_up.png");
				rect.Width = 13;
				rect.Height = 81;
				rect.X = 229;
				rect.Y = 220;
				matches[matchIndex].setCoord(229,220);
				matches[matchIndex].setRect(13, 81);
				matchIndex++;
				g->DrawImage(image, rect);

				//рисуем знак "="

				image = gcnew Bitmap("match_right.png");
				rect.Width = 81;
				rect.Height = 13;
				rect.X = 439;
				rect.Y = 233;
				matches[matchIndex].setCoord(439,233);
				matches[matchIndex].setRect(81, 13);
				matchIndex++;
				g->DrawImage(image, rect);
				image = gcnew Bitmap("match_right.png");
				rect.Width = 81;
				rect.Height = 13;
				rect.X = 439;
				rect.Y = 272;
				matches[matchIndex].setCoord(439,272);
				matches[matchIndex].setRect(81, 13);
				matchIndex++;
				g->DrawImage(image, rect);
			 }

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 /*
			 grForm = this->CreateGraphics();
			 myBitmap = gcnew Bitmap("C:\\Users\\Kirill\\Desktop\\ClientApp\\ClientApp\\background.png");
			 grForm = Graphics::FromImage(myBitmap);
			 */
			 //InitMatches();
			 this->label1->Text = "";
			 StartDraw();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 //клик на кнопку "Продолжить"
				 this->button1->Visible = false;	//скрываем кнопку "Старт"
				 this->button2->Visible = false;	//скрываем кнопку "Выход"
				 this->button3->Visible = true;		//показываем кнопку "Меню"
				 this->button4->Visible = false;	//скрываем кнопку "Продолжить"
		 }
private: System::Void pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Image);
				Graphics ^ g = Graphics::FromImage(bmp);
				this->pictureBox1->Image = bmp;
				for (int i = 0;i < 32;i++){
					if ((e->X > matches[i].getX() && e->X < matches[i].getX() + matches[i].getWidth()) && (e->Y > matches[i].getY() && e->Y < matches[i].getY() + matches[i].getHeight())){
						if (matches[i].isFull()){
							move = true;
							movedIndex = i;
							drawBWMatch(i,g);
							break;
						}
					}
				}
		 }
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (move){
				update();
				
				Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Image);
				Graphics ^ g = Graphics::FromImage(bmp);
				this->pictureBox1->Image = bmp;
				Bitmap ^ image;
				if (matches[movedIndex].getWidth() < 81) image = gcnew Bitmap("match_up.png");
				else image = gcnew Bitmap("match_right.png");
				Rectangle rect;
				rect.Width = matches[movedIndex].getWidth();
				rect.Height = matches[movedIndex].getHeight();
				
				rect.X = e->X;
				rect.Y = e->Y;
				g->DrawImage(image, rect);
				
			 }
							/*
							*/
		 }
private: System::Void pictureBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 move = false;	//Запрещаем перетаскивание
			 Bitmap ^ bmp = gcnew Bitmap(this->pictureBox1->Image);
			 Graphics ^ g = Graphics::FromImage(bmp);
			 this->pictureBox1->Image = bmp;
			 for (int i = 0;i < 32;i++){
				 if ((e->X > matches[i].getX() && e->X < matches[i].getX() + matches[i].getWidth()) && (e->Y > matches[i].getY() && e->Y < matches[i].getY() + matches[i].getHeight())){
						if (!matches[i].isFull()){
							drawOneMatch(i,g);
							drawBWMatch(movedIndex, g);
							break;
						}
						if (matches[i].isFull()){
							 drawOneMatch(movedIndex, g);
							 break;
						 }
					}
				 else{
					 drawOneMatch(movedIndex, g);
				 }
				 }
			 update();
			 checkLevel();
			}

		 private: void checkLevel(){
					  if (LevelNumber == 1){
						  if (checkFirstLevel()) {
							  MessageBox::Show("Уровень 1 пройден!");
							  drawLevelTwo();
						  }
					  }
					  else if (LevelNumber == 2){
						 if (checkSecondLevel()) {
							 MessageBox::Show("Уровень 2 пройден!"); 
							 drawLevelThree();
						 }
					  }
					  else if (LevelNumber == 3){
						  if (checkThirdLevel()){
							  MessageBox::Show("Уровень 3 пройден!");
							  MessageBox::Show("Игра окончена");
						      this->Close();
						  }
					  }
				  }


		//проверяем прохождение первого уровня
		private: bool checkFirstLevel(){
			if (matches[0].isFull() && matches[1].isFull() && matches[2].isFull()){
				return true;
			}
			else{
				return false;
			}
		}

		private: bool checkSecondLevel(){
			return true;
		}

		private: bool checkThirdLevel(){
			return true;
		}
};
}

