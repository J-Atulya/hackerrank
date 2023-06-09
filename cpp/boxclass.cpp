#include <iostream>
using namespace std;

class Box{
    private: int l,b,h;
    
    public:
    Box()
    {
        l=b=h=0;
    }   
    Box(int len, int bre, int hei)
    {
        l=len;
        b=bre;
        h=hei;
    }   
    Box(const Box& B) //copy contructor
    {
        l = B.l;
        b = B.b;
        h = B.h;
    }   
    int getLength(){
        return l;
    }
    int getBreath(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume()
    {
        long long x = (long long)getLength()*getBreath()*getHeight();
        return x ;
    }
    //overload operator <
    bool operator<(const Box& B) const
    {
        if (l < B.l)
            return true;
        else if (l==B.l)
        {
            if (b<B.b)
                return true;
            else if (b==B.b && h<B.h)
                return true;
            else return false;
        }
        else return false;
    }
};
//overload operator <<    
ostream& operator<<(ostream& out, Box& B) 
{
    out<<B.getLength()<<" ";
    out<<B.getBreath()<<" ";
    out<<B.getHeight();
    return out;
}
void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}