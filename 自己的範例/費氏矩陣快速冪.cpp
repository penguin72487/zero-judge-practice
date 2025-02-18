#include<iostream>
#include <initializer_list>
using namespace std;
class matrix{
public:
	int **data=nullptr;
	int r;
	int c;
	matrix(int i_r,int i_c,initializer_list<int> tmp)
	{
		r=i_r;
		c=i_c;
		data = new int*[r];
		for(int i = 0; i < r; i++)
		{
			data[i] = new int[c];
		}
		*this=tmp;
	}
	matrix(int i_r,int i_c)
	{
		r=i_r;
		c=i_c;
		data = new int*[r];
		for(int i = 0; i < r; i++)
		{
			data[i] = new int[c];
		}
	}
	~matrix()
	{
		for (int i=0; i<r; i++)
		{
			delete [] data[i];
		}
		for (int i=1; i<r; i++)
		{
			delete  data[i];
		}
	}

	void clear()
	{
		for (int i=0; i<r; i++)
		{
			delete [] data[i];
		}
		for (int i=1; i<r; i++)
		{
			delete  data[i];
		}
	}
	int* operator[](int i)
	{
		return data[i];
	}
	void operator=(initializer_list<int> tmp)
	{
		auto it=tmp.begin();
		for(int i=0;i<sizeof(data)/sizeof(int);i++)
		{
			for(int j=0;j<sizeof(data[0])/sizeof(int);j++)
			{
				data[i][j]=*it++;
			}
		}
	}
	 void operator=(int tmp[][sizeof(data[0])/sizeof(data[0][0])])
	{
		for(int i=0;i<sizeof(data)/sizeof(int);i++)
		{
			for(int j=0;j<sizeof(data[0])/sizeof(int);j++)
			{
				data[i][j]=tmp[i][j];
			}
		}

	}
	matrix operator*(matrix& tmp)
	{

		matrix ans(r,tmp.c);
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<tmp.c;j++)
			{
				ans[i][j]=0;
				for(int k=0;k<c;k++)
				{
					ans[i][j]=ans[i][j]+(data[i][k]*tmp[k][j]);
				}

			}
		}
		
		return ans;
	}

	matrix& operator*=(matrix& tmp)
	{

		return *this=((*this)*tmp);
	}
	matrix pow(int n)
	{
		matrix A=*this;
		matrix ans(2,2,{1,0,0,1});
	
		while(n){
			if(n&1){
	
				ans = ans*A;
	
			}
			A *=A;
	
			n >>= 1;
	
		}
	
		return ans;
	
	}


};
matrix pow(matrix& A,int n);
int main()
{
	matrix A(2,2,{1,1,1,0});
	matrix B(2,1,{1,0});
	matrix tmp(2,2);

	tmp=pow(A,13);












	for(int i=0;i<tmp.r;i++)
	{
		for(int j=0;j<tmp.c;j++)
		{
			cout<<tmp[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<1;j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<"\n";
	}
return 0;
}
matrix pow(matrix& A,int n)
{
	matrix c(2,2,{1,0,0,1});

	while(n){
		if(n&1){

			c = c*A;

		}
		A *=A;

		n >>= 1;

	}

	return c;

}

