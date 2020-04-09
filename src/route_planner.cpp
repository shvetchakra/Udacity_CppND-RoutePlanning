#include "route_planner.h"
#include <stack>
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    // TODO 2: Use the m_Model.FindClosestNode method to find the closest nodes to the starting and ending coordinates.
    // Store the nodes you find in the RoutePlanner's start_node and end_node attributes.
    this->start_node = &m_Model.FindClosestNode(start_x, start_y);
    this->end_node = &m_Model.FindClosestNode(end_x, end_y);
}


// TODO 3: Implement the CalculateHValue method.
// Tips:
// - You can use the distance to the end_node for the h value.
// - Node objects have a distance method to determine the distance to another node.

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    return node->distance(*this->end_node);

}


// TODO 4: Complete the AddNeighbors method to expand the current node by adding all unvisited neighbors to the open list.
// Tips:
// - Use the FindNeighbors() method of the current_node to populate current_node.neighbors vector with all the neighbors.
// - For each node in current_node.neighbors, set the parent, the h_value, the g_value. 
// - Use CalculateHValue below to implement the h-Value calculation.
// - For each node in current_node.neighbors, add the neighbor to open_list and set the node's visited attribute to true.

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {

    current_node->FindNeighbors();
    for (auto neighbor : current_node->neighbors)
    {
        if(neighbor->visited)
            continue;
        
        else
        {
            neighbor->parent = current_node;
            neighbor->h_value = CalculateHValue(neighbor);
            neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
            neighbor->visited = true;
            open_list.push_back(neighbor); 
        }
        
    }
}


// TODO 5: Complete the NextNode method to sort the open list and return the next node.
// Tips:
// - Sort the open_list according to the sum of the h value and g value.
// - Create a pointer to the node in the list with the lowest sum.
// - Remove that node from the open_list.
// - Return the pointer.
bool Compare(RouteModel::Node *a, RouteModel::Node *b) {
  float f1 =  a->g_value + a->h_value;// f1 = g1 + h1
  float f2 = b->g_value + b->h_value; // f2 = g2 + h2
    return f1 > f2; 
}
RouteModel::Node *RoutePlanner::NextNode() {
    std::sort(this->open_list.begin(), this->open_list.end(), Compare);
    if(!open_list.empty()){
    RouteModel::Node *nearestNode = open_list.back();
    open_list.pop_back();
    return nearestNode;
    }
    return nullptr;

}

/*void printNode(RouteModel::Node* it)
{
    std::cout<<"CurrentNode: ";
    std::cout<<"X: "<<it->x<<"Y: "<<it->y<<"F: "<<it->g_value+it->h_value<<std::endl;
        //<<it->g_value<<"H: "<<it->h_value<<std::endl;
}*/
// TODO 6: Complete the ConstructFinalPath method to return the final path found from your A* search.
// Tips:
// - This method should take the current (final) node as an argument and iteratively follow the 
//   chain of parents of nodes until the starting node is found.
// - For each node in the chain, add the distance from the node to its parent to the distance variable.
// - The returned vector should be in the correct order: the start node should be the first element
//   of the vector, the end node should be the last element.

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;
    std::stack<RouteModel::Node*> temp_path;
    // TODO: Implement your solution here.
    while(current_node != start_node)
    {
        temp_path.push(current_node);
        distance += current_node->distance(*current_node->parent);
        current_node = current_node->parent;
    }
    temp_path.push(current_node);
    while(!temp_path.empty())
    {
        path_found.push_back(*temp_path.top());
        //std::cout<<(*temp_path.top()).x<<"\t"<<(*temp_path.top()).y<<std::endl;
        //printNode(temp_path.top());
        temp_path.pop();
    }
    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;

}


// TODO 7: Write the A* Search algorithm here.
// Tips:
// - Use the AddNeighbors method to add all of the neighbors of the current node to the open_list.
// - Use the NextNode() method to sort the open_list and return the next node.
// - When the search has reached the end_node, use the ConstructFinalPath method to return the final path that was found.
// - Store the final path in the m_Model.path attribute before the method exits. This path will then be displayed on the map tile.
/*void printOpenList(std::vector<RouteModel::Node*> open_list)
{
    for(auto it = open_list.begin();it !=open_list.end();++it)
    {
        std::cout<<"X: "<<(*it)->x<<"Y: "<<(*it)->y<<"G: "
        <<(*it)->g_value<<"H: "<<(*it)->h_value<<"F: "<<(*it)->g_value+(*it)->h_value<<std::endl;
    }
}*/

void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;



    start_node->visited = true;
    start_node->g_value = 0;
    start_node->h_value = start_node->distance(*end_node); 
    current_node = start_node;
    open_list.push_back(current_node);
    //printOpenList(open_list);
    //AddNeighbors(current_node);
    //current_node = NextNode();
    //std::cout<<"Start:"<<std::endl;
    //printOpenList(open_list);
    //int count =0;
    while(!open_list.empty() )
    {
        if(current_node == end_node)
           { 
               break;
               }
        
        current_node = NextNode();
        //printNode(current_node);
        AddNeighbors(current_node);
        //printOpenList(open_list);
        //++count;
        
    }
    //std::cout<<"Total counts"<<count<<std::endl;
    m_Model.path = ConstructFinalPath(end_node);

}