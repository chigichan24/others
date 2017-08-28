def passStudents(scores: Map[String, Map[String, Int]]):Map[String, Int] = {
	val result = collection.mutable.Map[String,Int]()
	scores.foreach{
		val math = v._2.get("math")
		val english = v._2.get("english")
		for{
			m <- math
			e <- english
		}{
			result += v._1 -> (m+e)/2
		}
	}
	result.filter(_._2>=80).toMap
}
