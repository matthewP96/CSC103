/*
// "Connect Four" game implementation template (C) Acira Kawaguchi April, 2016
// This program is to implement a simmplified minimax-style intelegence by 
// evaluating board situation. Only I/O interface is shown below. Any addition of new method and classes is allowed. 
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorythm>
#include <cassert>

struct MyGameDef {	//profesional way to define global enumarable values.
	enum Player { Human, Progm, Empty };
	Player m_plpayer;
	MyGameDef (const Player p) : m_plpayer(p) {}
	operator Player() const{ return m_plpayer}
};

class Cell {	//representing a cell of a board.
	MyGameDef::Player m_occu; //marked 'Empty', 'Human', and 'Progm'.
public:
	Cell() : m_occu(MyGameDef::Empty) {}
	void setTurn(const MyGameDef::Player p) { assert(!isOccupied()); m_occu = p };
	bool isOccupied() const { return m_occu != MyGameDef::Empty }
	bool isMe(const MyGameDef::Player p) const { return m_occu == p; }
	void erase() { m_occu = MyGameDef::Empty; }
	friend ostream& operator<<(ostream& o, const Cell& c) {
		char mark;
		switch(c.m_occu) {
			case MyGameDef::Empty: return o << " . ";
			case MyGameDef::Human: return o << " o ";
			case MyGameDef::Progm: return o << " X ";
			default: abort();
		}
	}
};

class Eval {
	int m_conn; //connected to me.
	int m_poss; //possible spaces.
public:
	Eval(const int c = 0, const int p = 0) : m_conn(c), m_poss(p) {}
	bool isConnect4() const { return m_conn >= 3; }
	bool isWinning() const { return m_conn == 2 && m_poss >= 1; }
	int getValue() const { return m_conn * 2 + m_poss; }
	friend ostream& operator<<(ostream& o, const Eval& e) {
		return o << "(" << e.m_conn << ", " << e.m_poss << ")";
	}
};

class Turn {
	char m_turn;
	int m_score;
public:
	Turn(const char c = '\0', const int s = 0) : m_turn(c), m_score(s) {}
	~Turn();
	
};





























