#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include<map>
struct State {
	char a[3][3];
	State() 
	{
		a[0][0] = 'd';
		a[0][1] = 'i';
		a[0][2] = 'a';
		a[1][0] = 'p';
		a[1][1] = 'a';
		a[1][2] = 'z';
		a[2][0] = 'o';
		a[2][1] = 'n';
		a[2][2] = '_';
	}
	static State read() {
		State s;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) 
			{
				scanf_s(" %c", &s.a[i][j]);
			}
		}
		return s;
	}
	State shift(int di, int dj) const 
	{
		State next = *this;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				if (next.a[i][j] == '_')
				{
					int ni = i + di;
					int nj = j + dj;
					if (0 <= ni && ni < 3 && 0 <= nj && nj < 3) {
						std::swap(next.a[i][j], next.a[ni][nj]);
					}
					return next;
				}
			}
		}
		throw 1;
	}
	void print(State &dt) const 
	{
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				std::cout << std::setw(3)<< dt.a[i][j];
				
			}
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
};

int compare(const State &left, const State &right) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (left.a[i][j] != right.a[i][j]) {
				return left.a[i][j] - right.a[i][j];
			}
		}
	}
	return 0;
}
bool operator < (const State &left, const State &right) {
	return compare(left, right) < 0;
}
bool operator == (const State &left, const State &right) {
	return compare(left, right) == 0;
}
int main()
{
	State start;
	//State start = State::read();
	State finish = State::read();
	std::cout << "lets go" << std::endl;
	std::map<State, int> len;
	std::map<State,State> data;
	std::map<State, State> data2;
	std::queue<State> q;
	len[start] = 0;
	q.push(start);
	while (!q.empty()) 
	{
		State cur = q.front();
		q.pop();
		if (cur == finish) 
		{
			std::cout << len[cur] << std::endl;
			std::cout << "Right moves: " << std::endl;
			State next = cur;
			for (int i = 0; i < len[cur]; i++) 
			{
				data[next].print(data[next]);
				data2[next] = data[next];
				next = data2[next];
				std::cout << "______________" << std::endl;
			}
			return 0;
		}
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di * di + dj * dj == 1) {
					State next = cur.shift(di, dj);
					if (len.count(next) == 0) {
						len[next] = len[cur] + 1;
						data[next] = cur;
						q.push(next);
					}
				}
			}
		}

	}

	std::cout << "No solution" <<std::endl ;
	return 0;

}
