def firstOf[A](v1: Future[A], v2: Future[A]): Future[A] = {
    val p = Promise[A]()
    v1.onComplete(p.tryComplete)
    v2.onComplete(p.tryComplete)
    p.future
 }