#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>
#include <queue>

using namespace std;

struct segement
{
	long long L;//left boundary
	long long R;//right boundary
	long long W;//weight
	long long p;//position
};

struct segementR 
{
    bool operator()(segement const& a, segement const& b) const 
    {
        return a.R < b.R;
    }
};

bool sortL(segement A, segement B)
{
    return A.L<B.L;
}

void chooseseg(long long&first, long long&last, long long N, long long M, long long K, vector<segement> input, long long&answer, priority_queue <segement, vector<segement>, segementR >&heap, vector<long long>&position)
{
	long long K1 = K;

	position.assign(M+1,0);
	
	long long w = first+(last-first)/2;
	segement a;
	long long cant = 0;
	
	while(!heap.empty())
	{
		heap.pop();
	}


	long long x = 0;


	int i = 0;


	while(x < M)
	{
		if(x > 0)
		{
			position[x] += position[x-1];
		}

		while(i < input.size() && input[i].L == x)
		{
			heap.push(input[i]);
			i++;
		}

		while(position[x] < w)
		{
			if(heap.empty() == true)
			{
				cant = 1;
				break;
			}
			else
			{
				if(heap.top().R<=x)
				{
					heap.pop();
				}
				else
				{

					if(position[x] + heap.top().W > w)
					{
						a.L = heap.top().L;
						a.R = heap.top().R;
						a.W = heap.top().W - (w - position[x]);
						a.p = heap.top().p;
						
						// output1[heap.top().p] += (w - position[x]);
						K1 -= (w - position[x]);

						position[heap.top().R] -= (w - position[x]);
						position[x] += (w - position[x]);

						heap.pop();
						heap.push(a);
					}
					else
					{
						// output1[heap.top().p] += heap.top().W;
						K1 -= heap.top().W;
						position[x] += heap.top().W;

						position[heap.top().R] -= heap.top().W;

						heap.pop();
					}
				}
			}
		}
		if(cant == 1)
		{
			break;
		}
		x++;
	}
	if(cant == 1)
	{
		if(w-1 >= first)
		{
			last = w-1;
			chooseseg(first, last, N, M, K, input, answer, heap, position);
		}
		else
		{
			return;
		}
	}
	else if(K1 >= 0)
	{
		answer = w;
		if(last >= w+1)
		{
			first = w+1;
			chooseseg(first, last, N, M, K, input, answer, heap, position);
		}
		else
		{
			return;
		}
	}
	else if(K1 < 0)
	{
		if(w-1 >= first)
		{
			last = w-1;
			chooseseg(first, last, N, M, K, input, answer, heap, position);
		}
		else
		{
			return;
		}
	}

}
	


int main()
{
	long long N = 0;
	long long M = 0;
	long long K = 0;
	long long answer = 0;
	long long first;
	long long last;


	scanf("%lld %lld %lld", &N, &M, &K);

	vector<segement> input;


	vector<long long> output(N, 0);//index

	segement temp;

	for(long long i = 0; i < N; i++)
	{
		scanf("%lld %lld %lld", &temp.L, &temp.R, &temp.W);
		temp.p = i;
		input.push_back(temp);
	}

	priority_queue <segement, vector<segement>, segementR > heap;
	vector<long long> position(M+1, 0);

	sort(input.begin(), input.end(), sortL);


	first = 1;
	last = K;
	chooseseg(first, last, N, M, K, input, answer, heap, position);



	long long K1 = K;
	position.assign(M+1,0);
	segement a;
	
	while(!heap.empty())
	{
		heap.pop();
	}
	long long x = 0;
	int i = 0;


	while(x < M)
	{
		if(x > 0)
		{
			position[x] += position[x-1];
		}

		while(i < input.size() && input[i].L == x)
		{
			heap.push(input[i]);
			i++;
		}

		while(position[x] < answer)
		{
			if(heap.top().R<=x)
			{
				heap.pop();
			}
			else
			{

				if(position[x] + heap.top().W > answer)
				{
					a.L = heap.top().L;
					a.R = heap.top().R;
					a.W = heap.top().W - (answer - position[x]);
					a.p = heap.top().p;
					
					output[heap.top().p] += (answer - position[x]);
					K1 -= (answer - position[x]);

					position[heap.top().R] -= (answer - position[x]);
					position[x] += (answer - position[x]);

					heap.pop();
					heap.push(a);
				}
				else
				{
					output[heap.top().p] += heap.top().W;
					K1 -= heap.top().W;
					position[x] += heap.top().W;

					position[heap.top().R] -= heap.top().W;

					heap.pop();
				}
			}
		}
		x++;
	}


	printf("%lld\n", answer);
	for(long long i = 0; i < output.size(); i++)
	{
		printf("%lld ", output[i]);
	}

	return 0;

}