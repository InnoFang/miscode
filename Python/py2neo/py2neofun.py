# -*- coding: utf-8 -*-

from py2neo import Node, Relationship, Graph, NodeMatcher, RelationshipMatcher

class MyNode:
    def __init__(self, label, attrs):
        self.label = label
        self.attrs = attrs

def matchNode(graph, node):
    m_n = "_.name='{}'".format(node.attrs['name'])
    matcher = NodeMatcher(graph)
    return matcher.match(node.label).where(m_n).first()

def createNode(graph, node):
    # check the node exists or not before create it
    match = matchNode(graph, node)
    # 'match' is absolutely None before we create the node which we want to match
    if match is None:
        n = Node(node.label, **node.attrs)
        # create a graph node in graph database
        return graph.create(n)

def createRelationship(graph, node1, relation, node2):
    matched_node1 = matchNode(graph, node1)
    matched_node2 = matchNode(graph, node2)
    # ensure that the two nodes exist in graph database before create a relationship between them
    if matched_node1 and matched_node2:
        relationship = Relationship(matched_node1, relation, matched_node2)
        return graph.create(relationship)

def main():
    graph = Graph('http://localhost:7474/', username='neo4j', password='123123')

    nodes = [
        MyNode(label='Stock', attrs={'name': 'CMB', 'code': '600036'}), 
        MyNode(label='SecuritiesExchange', attrs={'name': 'ShanghaiStockExchange'}), 
    ]

    # Step 1:  Create some Nodes
    # for node in nodes:
    #     createNode(graph, node)

    # Step 2: Create a Relationship
    createRelationship(graph, nodes[0], 'StockExchange', nodes[1])

if __name__ == '__main__':
    main()
    