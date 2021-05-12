import java.util.*;

class Node implements Comparator<Node> {
    public int vertex;
    public int cost;

    Node() {
    }

    Node(int vertex, int cost) {
        this.vertex = vertex;
        this.cost = cost;
    }

    @Override
    public int compare(Node node1, Node node2) {
        if (node1.cost < node2.cost)
            return -1;
        if (node1.cost > node2.cost)
            return 1;
        return 0;
    }

    public String toString() {
        return ("vertex:" + vertex + " cost:" + cost);
    }
}

class Graph {
    static int V;
    static ArrayList<ArrayList<Node>> adj;
    static ArrayList<Boolean> visited;

    // Variables used for dijkstra algorithm
    int dist[];
    Set<Integer> settled;
    PriorityQueue<Node> pq;

    Graph(int v) {
        V = v;
        adj = new ArrayList<ArrayList<Node>>(v);

        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v, int cost) {
        adj.get(u).add(new Node(v, cost));
    }

    // A utility function to print the adjacency list
    void printGraph() {
        for (int i = 0; i < adj.size(); i++) {
            System.out.print(i + " head" + " -> ");
            for (int j = 0; j < adj.get(i).size(); j++) {
                System.out.print(adj.get(i).get(j).toString() + ", ");
            }
            System.out.println();
        }
    }

    void dfsUtil(int v) {
        visited.set(v, true);
        System.out.println("visited: " + v);

        for (Node u : adj.get(v)) {
            if (!visited.get(u.vertex))
                dfsUtil(u.vertex);
        }
    }

    void dfs() {
        visited = new ArrayList<Boolean>(Arrays.asList(new Boolean[V]));
        Collections.fill(visited, false);

        dfsUtil(0);
    }

    void findShortestPath() {
        findShortestPath(0);
    }

    // THIS is FAILING CURRENTLY FOR NON CONNECTED GRAPH
    // Take care all the edges are connected
    void findShortestPath(int source) {
        // Implement dijkstra algorithm
        dist = new int[V];
        settled = new HashSet<Integer>();
        pq = new PriorityQueue<Node>(V, new Node());

        // Initially taking all as infinity
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        dist[source] = 0;
        pq.add(new Node(source, 0));

        // Now run the greedy algorithm till all are settled
        while (settled.size() != V) {
            int u = pq.remove().vertex;
            settled.add(u);

            // Now check all the ones that are connected to u
            // and initialise the minimum value based on that

            for (int i = 0; i < adj.get(u).size(); i++) {
                Node v = adj.get(u).get(i);

                // If the node is already processed so leave that
                // and only take the ones that are not yet settled
                if (!settled.contains(v.vertex)) {
                    if (v.cost + dist[u] < dist[v.vertex]) {
                        dist[v.vertex] = v.cost + dist[u];
                    }

                    // Add this in the priority queue
                    pq.add(new Node(v.vertex, dist[v.vertex]));
                }

            }
        }

        // Finally print the distances
        System.out.println("The distances are: ");
        for (int i = 0; i < V; i++) {
            System.out.println(i + " " + dist[i]);
        }

    }

}

public class Main {

    public static void main(String args[]) {
        int V = 5; // No of edges

        Graph gp = new Graph(V);

        gp.addEdge(0, 1, 9);
        gp.addEdge(0, 2, 6);
        gp.addEdge(0, 3, 5);
        gp.addEdge(0, 4, 3);
        gp.addEdge(2, 1, 2);
        gp.addEdge(2, 3, 4);
        gp.printGraph();

        gp.dfs();

        gp.findShortestPath();

    }
}