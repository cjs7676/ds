#include<iostream>
#include<vector>
using namespace std;

struct SNode {
    int data;
    int Col;
    int Row;
    SNode* next;
};

struct MatrixNode {
    vector<vector<int> > Matrix;
    SNode* SNPTR;
};

SNode* CreateList(int Row, int Col, int data) {
    SNode* New = new SNode();
    New->data = data;
    New->Col = Col;
    New->Row = Row;
    New->next = NULL;
    return New;
}

MatrixNode* AddInList(MatrixNode* MNhead, int Row, int Col, int data) {
    MatrixNode* Mptr = MNhead;
    SNode* New = CreateList(Row, Col, data);
    if (Mptr->SNPTR == NULL) {
        Mptr->SNPTR = New;
        return MNhead;
    }
    New->next = Mptr->SNPTR;
    Mptr->SNPTR = New;
    return MNhead;
}

MatrixNode* ConstructSparseMatrix(MatrixNode* MNhead, vector<vector<int> > Matrix, SNode* SNhead) {
    MatrixNode* Mptr = MNhead;
    if (MNhead == NULL) {
        MNhead = new MatrixNode();
        MNhead->Matrix = Matrix;
        MNhead->SNPTR = SNhead;
    }
    Mptr = MNhead;
    for (int i = 0; i < Mptr->Matrix.size(); i++) {
        for (int j = 0; j < Mptr->Matrix[i].size(); j++) {
            if (Matrix[i][j] != 0) {
                MNhead = AddInList(MNhead, i, j, Matrix[i][j]);
            }
        }
    }
    return MNhead;
}

void DisplaySparseMatrix(MatrixNode* MNhead) {
    cout << "Sparse Matrix:" << endl;
    for (int i = 0; i < MNhead->Matrix.size(); i++) {
        for (int j = 0; j < MNhead->Matrix[i].size(); j++) {
            cout << MNhead->Matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLinked List Representation:" << endl;
    SNode* current = MNhead->SNPTR;
    while (current != NULL) {
        cout << "Row: " << current->Row << " Col: " << current->Col << " Data: " << current->data << endl;
        current = current->next;
    }
}

int main() {
    MatrixNode* MNhead = NULL;
    SNode* SNhead = NULL;

    // Initialize Matrix using constructor syntax
    vector<vector<int> > Matrix(5, vector<int>(5, 0));
    Matrix[0][1] = 2;
    Matrix[1][1] = 2;
    Matrix[2][2] = 3;
    Matrix[3][1] = 4;
    Matrix[3][4] = 5;
    Matrix[4][2] = 6;

    MNhead = ConstructSparseMatrix(MNhead, Matrix, SNhead);
    DisplaySparseMatrix(MNhead);
std::cout<<"";
    return 0;
}
