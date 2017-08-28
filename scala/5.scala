def passStudents(scores: Map[String, Map[String, Int]]):Map[String, Int] = {
	val result = collection.mutable.Map[String,Int]()
	for(
		v <- scores
	){ 
		val average = for(
			t <- v._2.get("math")
		)yield{
			for(s <- v._2.get("english"))yield{(s+t)/2}
		}
		for(p<-average){for(r<-p){result += v._1 -> r}}
	}
	result.filter(_._2>=80).toMap
}
