def passStudents(scores: Map[String, Map[String, Int]]):Map[String, Int] = {
	for{
		v <- scores
		m <- v._2.get("math")
		e <- v._2.get("english")
		if (m+e)/2>=80
	}yield{
		v._1 -> (m+e)/2
	}
}
