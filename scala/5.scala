def passStudents(scores: Map[String, Map[String, Int]]):Map[String, Int]  = {
	val keys = Set("math","english")
	val result = collection.mutable.Map[String,Int]()
	for(
		v <- scores
	){
		val fetched = v._2.filterKeys(keys)
		if(fetched.size == 2){
			val average = fetched.map(_._2).sum/fetched.size
			result += v._1 -> average
		}
	}
	result.filter(_._2>=80).toMap
}