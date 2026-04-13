fun main() {
    val t = readLine()!!.toInt()

    repeat(t) {
        val k = readLine()!!.toInt()

        val (a1, b1) = readLine()!!.split(" ").map { it.toInt() }
        val (a2, b2) = readLine()!!.split(" ").map { it.toInt() }

        val b3Max = minOf(k, 3 * k - (b1 + b2))

        val bTotal = b1 + b2 + b3Max
        val aTotal = a1 + a2

        if (bTotal > aTotal) {
            println("yes")
        } else {
            println("no")
        }
    }
}
