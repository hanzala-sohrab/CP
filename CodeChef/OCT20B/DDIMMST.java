import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class DDIMMST {
    static class Edge {
        long source;
        long weight;
        long destination;

        Edge(long s, long d, long w)
        {
            this.source = s;
            this.weight = w;
            this.destination = d;
        }
    }

    static long diff(ArrayList<Integer> x, ArrayList<Integer> y) {
        long d = 0;
        for (int i = 0; i < x.size(); ++i)
            d += Math.abs(x.get(i) - y.get(i));
        return d;
    }

    static int maxKey(long key[], Boolean mstSet[], int V)
    {
        // Initialize min value
        long min = Long.MAX_VALUE, min_index = -1;
 
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
 
        return (int)min_index;
    }
    public static void MST(long g[][]) {
        int V = g.length;
        int parent[] = new int[V];
 
        // Key values used to pick minimum weight edge in cut
        long key[] = new long[V];
 
        // To represent set of vertices included in MST
        Boolean mstSet[] = new Boolean[V];
 
        // Initialize all keys as INFINITE
        for (int i = 0; i < V; i++) {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }
 
        // Always include first 1st vertex in MST.
        key[0] = 0; // Make key 0 so that this vertex is
        // picked as first vertex
        parent[0] = -1; // First node is always root of MST
 
        // The MST will have V vertices
        for (int count = 0; count < V - 1; count++) {
            // Pick thd minimum key vertex from the set of vertices
            // not yet included in MST
            int u = maxKey(key, mstSet, V);
 
            // Add the picked vertex to the MST Set
            mstSet[u] = true;
 
            // Update key value and parent index of the adjacent
            // vertices of the picked vertex. Consider only those
            // vertices which are not yet included in MST
            for (int v = 0; v < V; v++)
 
                // graph[u][v] is non zero only for adjacent vertices of m
                // mstSet[v] is false for vertices not yet included in MST
                // Update the key only if graph[u][v] is smaller than key[v]
                if (g[u][v] != 0 && mstSet[v] == false && g[u][v] > key[v]) {
                    parent[v] = u;
                    key[v] = g[(int)u][(int)v];
                }
        }
        find(parent, g, V);
    }
    static void find(int parent[], long g[][], int V) {
        long s = 0;
        for (int i = 1; i < V; ++i)
            s += g[parent[i]][i];
        System.out.println(s);
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String nd[] = br.readLine().split(" ");
        final int n = Integer.parseInt(nd[0]);
        final int d = Integer.parseInt(nd[1]);
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        for (int i = 0; i < n; ++i)
        {
            String str[] = br.readLine().split(" ");
            ArrayList<Integer> values = new ArrayList<>();
            for (int k = 0; k < str.length; ++k)
                values.add(Integer.parseInt(str[k]));
            list.add(values);
        }
        ArrayList<Edge> edges = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                long w = diff(list.get(i), list.get(j));
                Edge c = new Edge(i, j, w);
                edges.add(c);
            }
        long gr[][] = new long[n][n];
        for (int i = 0; i < edges.size(); ++i)
        {
            gr[(int)edges.get(i).source][(int)edges.get(i).destination] = edges.get(i).weight;
            gr[(int)edges.get(i).destination][(int)edges.get(i).source] = edges.get(i).weight;
        }
        MST(gr);
    }
}