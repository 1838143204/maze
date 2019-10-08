const int n =49;

class node{
private:
	bool state;
	bool right;
	bool left;
	bool up;
	bool down;
public:
	node(){
	state=1;
	right=0;
	left=0;
	up=0;
	down=0;
}
	bool GetState(){return state;}
	void ChangeState(bool s){this->state=s;}
};

void randomgo(node (*maze)[n],int x, int y);

void CreatMaze(node (*maze)[n]);
