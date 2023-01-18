#include <iostream>
#include <vector>

int count = 0;
int max = 0;

struct Node
{
    int memberNumber;
    bool traitor;
    bool visited;
    std::vector<int> adjacent;
};


Node* NewNode(int memberNumber) //create node
{
    Node* newNode = new Node();
    newNode->memberNumber = memberNumber;
    newNode->traitor = false;
    newNode->visited = false;
    return newNode;
};

void findConnectables(Node* node, std::vector<Node*> &listofFamily)
{
  
    for (int i = 0; i < node->adjacent.size(); i++)
    {
        if (listofFamily[node->adjacent[i]]->visited == false && listofFamily[node->adjacent[i]]->traitor == false)
        {
            listofFamily[node->adjacent[i]]->visited = true;
            count++;
            //std:: cout<<listofFamily[node->test[i]]->memberNumber<<" is a child of "<<node->memberNumber<<" Count is "<<count<<"\n";
            findConnectables(listofFamily[node->adjacent[i]], listofFamily);
        }
    }

}

void findMax(Node* root, std::vector<Node*> &listofFamily)
{
    Node* temp;

    for(int i = 0; i < listofFamily.size(); i++)
    {
        temp = listofFamily[i];
        if (temp->traitor == false && temp->visited == false)
        {
            count = 0;
            findConnectables(temp, listofFamily);
        }
        //std::cout<<temp->memberNumber<<" is connected to "<<count<<"\n";
        if (max < count)
        {
            max = count;
        }

    }
}


int main() {
    int n;
    int m;
    int input;
    Node* root;
    root = NewNode(0);

    std::vector<Node*> family;
    family.push_back(root);
    std::vector<int> traitors;

    std::cin>>n>>m;

    for(int i = 1; i < n; i++)//initially create that many family members
    {
        family.push_back(NewNode(i));
    }

    for (int i = 0; i < n-1; i++)//allocate children accordingly
    {
        std::cin>>input;
        family[input]->adjacent.push_back(i+1);
        family[i+1]->adjacent.push_back(input);
    }

    for (int i = 0; i < m; i++)//which one are traitors
    {
        std::cin>>input;
        family[input]->traitor = true;
    }

    findMax(root, family);

    std::cout<<max;

    return 0;
}

