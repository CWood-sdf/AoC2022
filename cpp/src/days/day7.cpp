#include "day7.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::string;
class Directory {
	Directory* parent = nullptr;
	std::unordered_map<string, Directory*> children = {};
	std::unordered_set<string> files = {};
	string name = "";
	int weight = 0;

public:
	Directory(string name, Directory* parent) {
		this->name = name;
		this->weight = 0;
		this->parent = parent;
	}
	~Directory() {
		for (std::pair<string, Directory*> child : children) {
			delete child.second;
		}
	}
	void addFile(int weight, string name) {
		if (files.find(name) != files.end()) {
			return;
		}
		this->weight += weight;
		files.insert(name);
	}
	void makeChild(string name) {
		if (children.find(name) == children.end()) {
			return;
		}
		Directory* child = new Directory(name, this);
		children[name] = child;
	}
	Directory* getChild(string name) {
		return children[name];
	}
	std::unordered_map<string, Directory*>& getChildren() {
		return children;
	}
	Directory* getParent() {
		return parent;
	}
	int getWeight() {
		int ret = weight;
		for (std::pair<string, Directory*> child : children) {
			ret += child.second->getWeight();
		}
		return ret;
	}
	void prettyPrint(int depth = 0) {
		std::cout << "." << string(depth * 2, ' ') << "-" << name << " ("
				  << getWeight() << ")" << std::endl;
		for (std::pair<string, Directory*> child : children) {
			child.second->prettyPrint(depth + 1);
		}
	}
};
void Day7::init(bool test) {
	loadForDay(7, test);
}

int total(Directory* root) {
	int ret = 0;
	if (root->getWeight() < 100000) {
		ret += root->getWeight();
	}
	for (std::pair<string, Directory*> child : root->getChildren()) {
		ret += total(child.second);
	}
	return ret;
}
Directory* makeDirStructure(string input1) {
	Directory* root = new Directory("/", nullptr);
	Directory* current = root;
	string line = "";
	for (char& c : input1) {
		if (c == '\n') {
			if (line[0] == '$') {
				if (line == "$ ls") {
					// ignore bc we'll take care of this later
				} else if (line == "$ cd ..") {
					current = current->getParent();
				} else if (line == "$ cd /") {
					current = root;
				} else {
					string name = "";
					for (size_t i = 4; i < line.size(); i++) {
						name += line[i];
					}
					if (current->getChild(name) == nullptr) {
						current->makeChild(name);
					}
					current = current->getChild(name);
				}
			} else if (line[0] == 'd') {
				size_t i = 4;
				string name = "";
				while (i < line.size()) {
					name += line[i];
					i++;
				}
				current->makeChild(name);
			} else {
				string num = "";
				size_t i = 0;
				while (line[i] != ' ') {
					num += line[i];
					i++;
				}
				i++;
				string name = "";
				while (i < line.size()) {
					name += line[i];
					i++;
				}
				current->addFile(std::stoi(num), name);
			}
			line = "";
		} else {
			line += c;
		}
	}
	return root;
}
string Day7::runPart1() {
	Directory* root = makeDirStructure(input1);
	int ret = total(root);
	delete root;
	return std::to_string(ret);
}
int findSmallest(int needed, Directory* root) {
	int ret = 0;
	if (root->getWeight() >= needed) {
		ret = root->getWeight();
	}
	for (std::pair<string, Directory*> child : root->getChildren()) {
		int temp = findSmallest(needed, child.second);
		if (temp >= needed && temp < ret) {
			ret = temp;
		}
	}
	return ret;
}
string Day7::runPart2() {
	Directory* root = makeDirStructure(input1);
	int64_t space = 70000000 - root->getWeight();
	int64_t needed = 0;
	if (space < 30000000) {
		needed = 30000000 - space;
	}
	int ret = findSmallest(needed, root);
	delete root;
	return std::to_string(ret);
}
