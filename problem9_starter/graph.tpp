#include "graph.hpp"
#include <map>
#include <set>
#include <stack>
#include <queue>

template <typename ItemType>
Graph<ItemType>::Graph()
{
}

template <typename ItemType>
int Graph<ItemType>::getNumVertices() const
{
  return adjList.size();
}

template <typename ItemType>
int Graph<ItemType>::getNumEdges() const
{
  int count = 0;
  for (const auto &pair : adjList) {
      count += pair.second.size();
  }
  return count / 2;
}

template <typename ItemType>
bool Graph<ItemType>::add(ItemType start, ItemType end)
{
  if (start == end)
  return false;
if (adjList[start].count(end))
  return false;
adjList[start].insert(end);
adjList[end].insert(start);
std::set<ItemType> visited;
std::stack<ItemType> s;
s.push(start);
while (!s.empty()) {
  ItemType v = s.top(); s.pop();
  visited.insert(v);
  for (ItemType neighbor : adjList[v]) {
      if (!visited.count(neighbor))
          s.push(neighbor);
  }
}

if (visited.size() != adjList.size()) {
  adjList[start].erase(end);
  adjList[end].erase(start);
  if (adjList[start].empty()) adjList.erase(start);
  if (adjList[end].empty()) adjList.erase(end);
  return false;
}
return true;
}

template <typename ItemType>
bool Graph<ItemType>::remove(ItemType start, ItemType end)
{
  if (start == end)
  return false;
if (!adjList.count(start) || !adjList[start].count(end))
  return false;
adjList[start].erase(end);
adjList[end].erase(start);
if (adjList[start].empty()) adjList.erase(start);
if (adjList[end].empty()) adjList.erase(end);
return true;
}

template <typename ItemType>
void Graph<ItemType>::depthFirstTraversal(ItemType start, void visit(ItemType &))
{
  std::set<ItemType> visited;
  std::stack<ItemType> s;
  s.push(start);
  while (!s.empty()) {
      ItemType v = s.top(); s.pop();
      if (visited.count(v)) continue;
      visit(v);
      visited.insert(v);
      for (auto it = adjList[v].rbegin(); it != adjList[v].rend(); ++it) {
          if (!visited.count(*it))
              s.push(*it);
      }
  }

}

template <typename ItemType>
void Graph<ItemType>::breadthFirstTraversal(ItemType start, void visit(ItemType &))
{
  std::set<ItemType> visited;
  std::queue<ItemType> q;
  q.push(start);
  while (!q.empty()) {
      ItemType v = q.front(); q.pop();
      if (visited.count(v)) continue;
      visit(v);
      visited.insert(v);
      for (ItemType neighbor : adjList[v]) {
          if (!visited.count(neighbor))
              q.push(neighbor);
      }
  }
}