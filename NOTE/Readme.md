# Note

1. Avoid push_back and prefer emplace_back instead.
2. For possible big maps, add reserve() when you use a vector to avoid a lot of resize.
