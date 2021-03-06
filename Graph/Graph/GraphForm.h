#pragma once
#include <ctime>
#include "Graph.h"
#include "Pos.h"

const int ARROW_OFFSET = 30;
const int RANDOM_VERTEX_COUNT = 30;

namespace GraphProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GraphForm
	/// </summary>
	public ref class GraphForm : public System::Windows::Forms::Form
	{
	public:
		GraphForm(void)
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
		~GraphForm()
		{
			if (components)
			{
				delete components;
				delete g;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  primButton;
	private: System::Windows::Forms::Button^  kruskalButton;
	protected:


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  dijkstraButton;
	private: System::Windows::Forms::TextBox^  vertexBox;


	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  resetButton;
	private: System::Windows::Forms::Button^  breadthButton;
	private: System::Windows::Forms::Button^  depthButton;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  searchVertexBox;
	private: System::Windows::Forms::Label^  SearchLabel;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  dijkstraStart;
	private: System::Windows::Forms::TextBox^  dijkstraEnd;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  undirectedButton;
	private: System::Windows::Forms::Button^  acyclicButton;


	private: System::Windows::Forms::Button^  cyclicButton;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  randomButton;




	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private:
		//Vertices
		Label^ newLabel(System::String ^text, int x, int y){
			Label^ l = gcnew Label();
			//l->AutoSize = true;
			l->BackColor = System::Drawing::Color::LightBlue;
			l->Location = System::Drawing::Point(x, y);
			l->Name = L"label1asdf";
			l->Size = System::Drawing::Size(32, 32);
			l->TabIndex = 0;
			l->Text = text;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel1->Controls->Add(l);
			return l;
		}

		//Edges
		Label^ newLabel2(System::String^ text, int x, int y){
			Label^ l = gcnew Label();
			//l->AutoSize = true;
			l->BackColor = System::Drawing::Color::Transparent;
			l->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			l->Location = System::Drawing::Point(x, y);
			l->Name = L"label1asdf";
			l->Size = System::Drawing::Size(16, 16);
			l->TabIndex = 0;
			l->Text = text;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->panel1->Controls->Add(l);
			return l;
		}
		void MarkLabel(Label ^label, bool mark){
			if (mark){
				label->BackColor = System::Drawing::Color::Blue;
				label->ForeColor = System::Drawing::Color::White;
			}
			else{
				label->BackColor = System::Drawing::Color::LightBlue;
				label->ForeColor = System::Drawing::Color::Black;
			}
		}

		void UpdateLabels(){
			for (int i = 0; i < graph->VertexCount(); i++){
				if (graph->GetVertex(i)->IsMarked()){
					MarkLabel(labels[i], true);
				}
				else{
					MarkLabel(labels[i], false);
				}
			}
		}

		void LoadVertices(Graph<Pos>* g, string filename){
			ifstream file;
			file.open(filename);
			if (file.fail()){
				file.close();
				System::Windows::Forms::Application::Exit();
			}
			while (!file.eof()){
				string n, x, y;
				file >> n >> x >> y;
				if (n == "")
					continue;
				else if (n[0] == 'T'){
					//May not be used
					continue;
				}
				else{
					Pos p;
					p.X = stoi(x);
					p.Y = stoi(y);
					g->AddVertex(stoi(n), p);
				}
			}
			file.close();
			g->SetupMatrices();
		}

		void LoadRandomVertices(Graph<Pos>* g){
			for (int i = 0; i < RANDOM_VERTEX_COUNT; i++){
				Pos p;
				p.X = 20 + rand() % 630;
				p.Y = 20 + rand() % 630;
				g->AddVertex(i, p);
			}
			g->SetupMatrices();
		}
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Graphics ^g;
		Pen ^edgePen;
		Pen ^markedEdgePen;
		cli::array<Label^>^ labels;
		bool graphLoaded = false;
		int labelCount = 0;

		Graph<Pos> *graph = nullptr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->primButton = (gcnew System::Windows::Forms::Button());
			this->kruskalButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dijkstraButton = (gcnew System::Windows::Forms::Button());
			this->vertexBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->breadthButton = (gcnew System::Windows::Forms::Button());
			this->depthButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->searchVertexBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchLabel = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->dijkstraStart = (gcnew System::Windows::Forms::TextBox());
			this->dijkstraEnd = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->undirectedButton = (gcnew System::Windows::Forms::Button());
			this->acyclicButton = (gcnew System::Windows::Forms::Button());
			this->cyclicButton = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->randomButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(759, 737);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraphForm::panel1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(973, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Make a Spanning Tree";
			// 
			// primButton
			// 
			this->primButton->Location = System::Drawing::Point(976, 80);
			this->primButton->Name = L"primButton";
			this->primButton->Size = System::Drawing::Size(107, 23);
			this->primButton->TabIndex = 2;
			this->primButton->Text = L"Prim\'s Algorithm";
			this->primButton->UseVisualStyleBackColor = true;
			this->primButton->Click += gcnew System::EventHandler(this, &GraphForm::primButton_Click);
			// 
			// kruskalButton
			// 
			this->kruskalButton->Location = System::Drawing::Point(976, 109);
			this->kruskalButton->Name = L"kruskalButton";
			this->kruskalButton->Size = System::Drawing::Size(107, 23);
			this->kruskalButton->TabIndex = 3;
			this->kruskalButton->Text = L"Kruskal\'s Algorithm";
			this->kruskalButton->UseVisualStyleBackColor = true;
			this->kruskalButton->Click += gcnew System::EventHandler(this, &GraphForm::kruskalButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(997, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Make a Path";
			// 
			// dijkstraButton
			// 
			this->dijkstraButton->Location = System::Drawing::Point(976, 187);
			this->dijkstraButton->Name = L"dijkstraButton";
			this->dijkstraButton->Size = System::Drawing::Size(107, 23);
			this->dijkstraButton->TabIndex = 5;
			this->dijkstraButton->Text = L"Dijkstra\'s Algorithm";
			this->dijkstraButton->UseVisualStyleBackColor = true;
			this->dijkstraButton->Click += gcnew System::EventHandler(this, &GraphForm::dijkstraButton_Click);
			// 
			// vertexBox
			// 
			this->vertexBox->Location = System::Drawing::Point(933, 80);
			this->vertexBox->MaxLength = 2;
			this->vertexBox->Name = L"vertexBox";
			this->vertexBox->Size = System::Drawing::Size(37, 20);
			this->vertexBox->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(891, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Starting Vertex";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(893, 324);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(139, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Spanning Tree/Path Output";
			// 
			// resetButton
			// 
			this->resetButton->Location = System::Drawing::Point(1008, 278);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(75, 23);
			this->resetButton->TabIndex = 10;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &GraphForm::resetButton_Click);
			// 
			// breadthButton
			// 
			this->breadthButton->Location = System::Drawing::Point(1000, 646);
			this->breadthButton->Name = L"breadthButton";
			this->breadthButton->Size = System::Drawing::Size(109, 23);
			this->breadthButton->TabIndex = 11;
			this->breadthButton->Text = L"Breadth-first Search";
			this->breadthButton->UseVisualStyleBackColor = true;
			this->breadthButton->Click += gcnew System::EventHandler(this, &GraphForm::breadthButton_Click);
			// 
			// depthButton
			// 
			this->depthButton->Location = System::Drawing::Point(1000, 617);
			this->depthButton->Name = L"depthButton";
			this->depthButton->Size = System::Drawing::Size(109, 23);
			this->depthButton->TabIndex = 12;
			this->depthButton->Text = L"Depth-first Search";
			this->depthButton->UseVisualStyleBackColor = true;
			this->depthButton->Click += gcnew System::EventHandler(this, &GraphForm::depthButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(989, 594);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Starting Vertex";
			// 
			// searchVertexBox
			// 
			this->searchVertexBox->Location = System::Drawing::Point(1072, 591);
			this->searchVertexBox->MaxLength = 2;
			this->searchVertexBox->Name = L"searchVertexBox";
			this->searchVertexBox->Size = System::Drawing::Size(37, 20);
			this->searchVertexBox->TabIndex = 6;
			// 
			// SearchLabel
			// 
			this->SearchLabel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SearchLabel->Location = System::Drawing::Point(781, 692);
			this->SearchLabel->Name = L"SearchLabel";
			this->SearchLabel->Size = System::Drawing::Size(328, 65);
			this->SearchLabel->TabIndex = 13;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(781, 340);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(328, 225);
			this->listBox1->TabIndex = 14;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(947, 138);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(142, 17);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->Text = L"Show only spanning tree";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &GraphForm::checkBox1_CheckedChanged);
			// 
			// dijkstraStart
			// 
			this->dijkstraStart->Location = System::Drawing::Point(893, 187);
			this->dijkstraStart->MaxLength = 2;
			this->dijkstraStart->Name = L"dijkstraStart";
			this->dijkstraStart->Size = System::Drawing::Size(37, 20);
			this->dijkstraStart->TabIndex = 6;
			// 
			// dijkstraEnd
			// 
			this->dijkstraEnd->Location = System::Drawing::Point(936, 187);
			this->dijkstraEnd->MaxLength = 2;
			this->dijkstraEnd->Name = L"dijkstraEnd";
			this->dijkstraEnd->Size = System::Drawing::Size(37, 20);
			this->dijkstraEnd->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(893, 171);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Start";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(938, 171);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"End";
			// 
			// undirectedButton
			// 
			this->undirectedButton->Location = System::Drawing::Point(781, 31);
			this->undirectedButton->Name = L"undirectedButton";
			this->undirectedButton->Size = System::Drawing::Size(102, 23);
			this->undirectedButton->TabIndex = 16;
			this->undirectedButton->Text = L"Undirected Graph";
			this->undirectedButton->UseVisualStyleBackColor = true;
			this->undirectedButton->Click += gcnew System::EventHandler(this, &GraphForm::undirectedButton_Click);
			// 
			// acyclicButton
			// 
			this->acyclicButton->Location = System::Drawing::Point(1015, 31);
			this->acyclicButton->Name = L"acyclicButton";
			this->acyclicButton->Size = System::Drawing::Size(102, 23);
			this->acyclicButton->TabIndex = 16;
			this->acyclicButton->Text = L"Acyclic Graph";
			this->acyclicButton->UseVisualStyleBackColor = true;
			this->acyclicButton->Click += gcnew System::EventHandler(this, &GraphForm::acyclicButton_Click);
			// 
			// cyclicButton
			// 
			this->cyclicButton->Location = System::Drawing::Point(898, 31);
			this->cyclicButton->Name = L"cyclicButton";
			this->cyclicButton->Size = System::Drawing::Size(102, 23);
			this->cyclicButton->TabIndex = 16;
			this->cyclicButton->Text = L"Cyclic Graph";
			this->cyclicButton->UseVisualStyleBackColor = true;
			this->cyclicButton->Click += gcnew System::EventHandler(this, &GraphForm::cyclicButton_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(922, 15);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Load a Graph";
			// 
			// randomButton
			// 
			this->randomButton->Location = System::Drawing::Point(781, 64);
			this->randomButton->Name = L"randomButton";
			this->randomButton->Size = System::Drawing::Size(102, 23);
			this->randomButton->TabIndex = 16;
			this->randomButton->Text = L"Random Graph";
			this->randomButton->UseVisualStyleBackColor = true;
			this->randomButton->Click += gcnew System::EventHandler(this, &GraphForm::randomButton_Click);
			// 
			// GraphForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1129, 762);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->randomButton);
			this->Controls->Add(this->cyclicButton);
			this->Controls->Add(this->acyclicButton);
			this->Controls->Add(this->undirectedButton);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->SearchLabel);
			this->Controls->Add(this->depthButton);
			this->Controls->Add(this->breadthButton);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->searchVertexBox);
			this->Controls->Add(this->dijkstraEnd);
			this->Controls->Add(this->dijkstraStart);
			this->Controls->Add(this->vertexBox);
			this->Controls->Add(this->dijkstraButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->kruskalButton);
			this->Controls->Add(this->primButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"GraphForm";
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &GraphForm::GraphForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void LoadGraph(string graphName){
			if (graph != nullptr){
				delete graph;
			}
			graph = new Graph<Pos>();
			LoadVertices(graph, graphName + " Graph Vertices.txt");
			graph->LoadEdges(graphName + " Graph Edges.txt");
			labels = gcnew cli::array<Label^>(graph->VertexCount());

			for (int i = 0; i < labelCount; i++){
				panel1->Controls->Remove(labels[i]);
			}
			labelCount = 0;

			//Display edge weights
			//O(n^2)
			for (int i = 0; i < graph->VertexCount(); i++){
				Label^ l = newLabel(i.ToString(), graph->GetVertex(i)->GetT().X, graph->GetVertex(i)->GetT().Y);
				labels[labelCount] = l;
				labelCount++;

				for (int j = 0; j < graph->VertexCount(); j++){
					int w = graph->GetEdgeWeight(i, j);
					if (w == 0)
						continue;
					Pos p1 = graph->GetVertex(i)->GetT();
					Pos p2 = graph->GetVertex(j)->GetT();
					int x1 = p1.X;
					int y1 = p1.Y;
					int x2 = p2.X;
					int y2 = p2.Y;
					Point center = Point(x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
					newLabel2(w.ToString(), center.X + 8, center.Y + 8);
				}
			}
			EnableGraphButtons(false);
			graphLoaded = true;
			panel1->Refresh();
		}

		void LoadGraphRandom(){
			if (graph != nullptr){
				delete graph;
			}
			graph = new Graph<Pos>();
			LoadRandomVertices(graph);
			graph->LoadRandomEdges();
			labels = gcnew cli::array<Label^>(graph->VertexCount());

			for (int i = 0; i < graph->VertexCount(); i++){
				Label^ l = newLabel(i.ToString(), graph->GetVertex(i)->GetT().X, graph->GetVertex(i)->GetT().Y);
				labels[labelCount] = l;
				labelCount++;

				for (int j = 0; j < graph->VertexCount(); j++){
					int w = graph->GetEdgeWeight(i, j);
					if (w == 0)
						continue;
					Pos p1 = graph->GetVertex(i)->GetT();
					Pos p2 = graph->GetVertex(j)->GetT();
					int x1 = p1.X;
					int y1 = p1.Y;
					int x2 = p2.X;
					int y2 = p2.Y;
					Point center = Point(x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
					newLabel2(w.ToString(), center.X + 8, center.Y + 8);
				}
			}
			EnableGraphButtons(false);
			graphLoaded = true;
			panel1->Refresh();
		}

		void EnableButtons(bool enabled){
			primButton->Enabled = enabled;
			kruskalButton->Enabled = enabled;
			dijkstraButton->Enabled = enabled;
			resetButton->Enabled = enabled;
			breadthButton->Enabled = enabled;
			depthButton->Enabled = enabled;
		}

		void EnableGraphButtons(bool enabled){
			undirectedButton->Enabled = enabled;
			cyclicButton->Enabled = enabled;
			acyclicButton->Enabled = enabled;
		}

#pragma endregion
	private: System::Void GraphForm_Load(System::Object^  sender, System::EventArgs^  e) {
		srand(time(0));
		graph = nullptr;
		labelCount = 0;
		g = panel1->CreateGraphics();
		edgePen = gcnew Pen(Color::LightBlue, 6);
		edgePen->EndCap = Drawing2D::LineCap::ArrowAnchor;
		markedEdgePen = gcnew Pen(Color::Blue, 6);
		markedEdgePen->EndCap = Drawing2D::LineCap::ArrowAnchor;
		bool result = false;

		EnableButtons(false);
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		if (!graphLoaded)
			return;
		//Display edges
		for (int i = 0; i < graph->VertexCount(); i++){
			for (int j = 0; j < graph->VertexCount(); j++){
				int w = graph->GetEdgeWeight(i, j);
				if (w == 0)
					continue;
				Vertex<Pos> *v1 = graph->GetVertex(i);
				Vertex<Pos> *v2 = graph->GetVertex(j);
				int x1_ = v1->GetT().X;
				int y1_ = v1->GetT().Y;
				int x2_ = v2->GetT().X;
				int y2_ = v2->GetT().Y;

				float direction = Math::Atan2(y2_ - y1_, x2_ - x1_);

				int x1 = x1_ + (ARROW_OFFSET * Math::Cos(direction));
				int y1 = y1_ + (ARROW_OFFSET * Math::Sin(direction));
				int x2 = x2_ - (ARROW_OFFSET * Math::Cos(direction));
				int y2 = y2_ - (ARROW_OFFSET * Math::Sin(direction));

				if (!graph->GetEdgeMarked(i, j)){
					if (!checkBox1->Checked){
						g->DrawLine(edgePen, x1 + 16, y1 + 16, x2 + 16, y2 + 16);
					}
				}
				else{
					g->DrawLine(markedEdgePen, x1 + 16, y1 + 16, x2 + 16, y2 + 16);
				}
			}
		}
	}
	private: System::Void primButton_Click(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		ListBox::ObjectCollection ^col = gcnew ListBox::ObjectCollection(listBox1);
		int num = -1;
		bool result = int::TryParse(vertexBox->Text, num);
		if (!result || num < 0 || num >= graph->VertexCount())
			return;

		graph->Prim(num, col);
		UpdateLabels();
		panel1->Refresh();
	}
	private: System::Void resetButton_Click(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		graph->MarkEntireGraph(false);
		UpdateLabels();
		panel1->Refresh();
	}
private: System::Void kruskalButton_Click(System::Object^  sender, System::EventArgs^  e) {
	listBox1->Items->Clear();
	ListBox::ObjectCollection ^col = gcnew ListBox::ObjectCollection(listBox1);
	graph->Kruskal(col);
	UpdateLabels();
	panel1->Refresh();
}
private: System::Void depthButton_Click(System::Object^  sender, System::EventArgs^  e) {
	int num = -1;
	String ^result = gcnew String("");
	bool success = int::TryParse(searchVertexBox->Text, num);
	if (!success || num < 0 || num >= graph->VertexCount())
		return;

	graph->DepthFirstSearch(num, result);

	SearchLabel->Text = result;
	
	graph->VisitEntireGraph(false);
	graph->MarkEntireGraph(false);
	UpdateLabels();

	panel1->Refresh();
}
private: System::Void breadthButton_Click(System::Object^  sender, System::EventArgs^  e) {
	graph->MarkEntireGraph(false);
	int num = -1;
	bool success = int::TryParse(searchVertexBox->Text, num);
	if (!success || num < 0 || num >= graph->VertexCount())
		return;

	String ^result = gcnew String(num + " ");
	graph->GetVertex(num)->Mark(true);

	graph->BreadthFirstSearch(num, result);

	SearchLabel->Text = result;

	graph->VisitEntireGraph(false);
	graph->MarkEntireGraph(false);
	UpdateLabels();

	panel1->Refresh();
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	panel1->Refresh();
}
	private: System::Void dijkstraButton_Click(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		int start = -1, end = -1;
		bool success = int::TryParse(dijkstraStart->Text, start);
		if (!success || start < 0 || start >= graph->VertexCount())
			return;

		success = int::TryParse(dijkstraEnd->Text, end);
		if (!success || end < 0 || end >= graph->VertexCount())
			return;

		bool pathResult = graph->Dijkstra(start, end);
		if (!pathResult)
			listBox1->Items->Add("Unable to construct a path from " + start + " to " + end);
		UpdateLabels();
		panel1->Refresh();
	}
private: System::Void cyclicButton_Click(System::Object^  sender, System::EventArgs^  e) {
	LoadGraph("Cyclic");
	EnableButtons(true);
}
private: System::Void undirectedButton_Click(System::Object^  sender, System::EventArgs^  e) {
	LoadGraph("Small");
	EnableButtons(true);
}
private: System::Void acyclicButton_Click(System::Object^  sender, System::EventArgs^  e) {
	LoadGraph("Acyclic");
	EnableButtons(true);
}
private: System::Void randomButton_Click(System::Object^  sender, System::EventArgs^  e) {
	LoadGraphRandom();
	EnableButtons(true);
}
};
}