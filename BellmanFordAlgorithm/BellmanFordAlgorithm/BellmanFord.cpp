//
//  BellmanFord.cpp
//  BellmanFordAlgorithm
//
//  Created by Aleksander Konstantinov on 12/15/18.
//  Copyright © 2018 Oleksandr Konstantinov. All rights reserved.
//

#include "BellmanFord.h"
#include <iostream>

void BellmanFord::operator()(size_t sourceVertexIndex, size_t targetVertexIndex) const {
    
    if (sourceVertexIndex >= vertexList.size() || targetVertexIndex >= vertexList.size())
        return;
    
    Vertex& sourceVertex = vertexList[sourceVertexIndex];
    Vertex& targetVertex = vertexList[targetVertexIndex];
    
    
    sourceVertex.setMinDistance(0);
    
    for (auto const &vertex : vertexList) {
        (void)vertex; // remove unsused variable warning
        
        for (auto const &edge : edgeList) {
            
            /*
             * ez adja a O(V*E) complexityt mindig, nem lesz olyan mint Djokstra algoritmusnal ahol a priority queue
             *     pontos implekemntalasatol fugg a futasi ido
             *         Itt lehet hasznalni listat vagy arrayt teljesen mindegx !!!
             *      DE ... lehet hogy O(E) = V*V es igy egy V*V*V algoritmust kapunk ... tehat lassabb a Dijkstra algoritmusnal mindig
             *              ~ a Dijkstra akar linearois time cmplecxitivel is tudna futni
             */
            
            if ( edge.getStartVertex()->getMinDistance() == INT_MAX ) {
                continue;
            }
            
            int newDistance = edge.getStartVertex()->getMinDistance() + edge.getWeight();
            
            if (newDistance < edge.getTargetVertex()->getMinDistance()) {
                edge.getTargetVertex()->setMinDistance(newDistance);
                edge.getTargetVertex()->setPreviousVertex(edge.getStartVertex());
            }
        }
    }
    
    for (Edge edge : edgeList) {
        if (edge.getStartVertex()->getMinDistance() != INT_MAX) {
            if ( hasCycle(edge) ) {
                cout << "Negative edge weight cycles detected!\n";
                return;
            }
        }
    }
    
    if (targetVertex.getMinDistance() != INT_MAX) {
        cout << "There is a shortest path from source to target, with cost: " << targetVertex.getMinDistance() << '\n';
        
        Vertex *actualVErtex = &targetVertex;
        while( actualVErtex->getPreviousVertex() != nullptr ){
            cout << *actualVErtex << '-';
            actualVErtex = actualVErtex->getPreviousVertex();
        }
        
        cout << '\n';
        
    } else {
        cout << "There is no path from source to target...\n";
    }
}

bool BellmanFord::hasCycle(Edge const &edge) const {
    return edge.getTargetVertex()->getMinDistance() > edge.getStartVertex()->getMinDistance() + edge.getWeight();
}
