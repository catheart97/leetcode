using System.Collections.Generic;

using VerticalData = System.Tuple<int, int>;
using QueueData = System.Tuple<TreeNode, int>;

// Definition for a binary tree node.
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val=0, TreeNode left=null, TreeNode right=null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    private static void AddValue(
        IList<int> lnode, in int value, in int depth, Dictionary<IList<int>, VerticalData> visited
    ) {
        // Item2 gives us the depth we last stored a value 
        // Item1 gives use the index of the first element stored at that depth
        var v = visited!.GetValueOrDefault(lnode, null);
        if (v != null && v.Item2 == depth)
        {
            int pi = v.Item1;
            var ii = ((List<int>) lnode).BinarySearch(pi, lnode.Count - pi, value, null);
            ii = ii < 0 ? ~ii : ii;
            lnode.Insert(ii, value);
        }
        else 
        {
            lnode.Add(value);
            visited[lnode] = new VerticalData(lnode.Count - 1, depth);
        }
    }

    public IList<IList<int>> VerticalTraversal(TreeNode root)
    {
        var result = new List<IList<int>>() { new List<int>() };
        var visited = new Dictionary<IList<int>, VerticalData>();
        var queue = new Queue<QueueData>();
        queue.Enqueue(new QueueData(root, 0));

        int ridx = 0; // indicates where the root node in result is at all times
        for (int depth = 0; queue.Count > 0; ++depth)
        {
            int qCount = queue.Count;
            for (int i = 0; i < qCount; ++i)
            {
                var node_idx = queue.Dequeue();
                var node = node_idx.Item1;
                var idx = node_idx.Item2;

                AddValue(result[ridx + idx], node.val, depth, visited);

                if (node.left != null)
                {
                    if (ridx + idx == 0)
                    { 
                        result.Insert(0, new List<int>());
                        ridx++;
                    }
                    queue.Enqueue(new QueueData(node.left!, idx - 1));
                }

                if (node.right != null)
                {
                    if (ridx + idx == result.Count - 1) result.Add(new List<int>());
                    queue.Enqueue(new QueueData(node.right!, idx + 1));
                }
            }
        }

        return result;
    }
}