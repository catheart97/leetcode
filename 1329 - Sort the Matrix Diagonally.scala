object Solution {
    def diagonalSort(mat: Array[Array[Int]]): Array[Array[Int]] = {
        val m = mat.length
        val n = mat(0).length
        var d = new Array[Int](n.min(m))
        
        val sortDiagonal = (i : Int, j : Int) => {
            val c = (m - i).min(n - j)
            for (k <- 0 until c) d(k) = mat(i + k)(j + k)
            d.view.slice(0, c).toSeq.sorted.copyToArray(d, 0)
            for (k <- 0 until c) mat(i + k)(j + k) = d(k)
        }

        for (i <- 0 until m - 1) sortDiagonal(i, 0)
        for (j <- 1 until n - 1) sortDiagonal(0, j)

        mat
    }
}

object Main extends App {
    val matprint = 
        (input : Array[Array[Int]]) => println(input.map(v => v.mkString(" ")).mkString("\n"))

    val input = Array(Array(3,3,1,1),Array(2,2,1,2),Array(1,1,1,2))
    matprint(input)
    println("")
    matprint(Solution.diagonalSort(input))
}