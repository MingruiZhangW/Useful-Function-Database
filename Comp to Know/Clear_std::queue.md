A common idiom for clearing standard containers is swapping with an empty version of the container:

      void clear( std::queue<int> &q )
      {
         std::queue<int> empty;
         std::swap( q, empty );
      }
It is also the only way of actually clearing the memory held inside some containers (std::vector)

Better yet is std::queue<int>().swap(q). With copy and swap idiom, all this should be equivalent to q = std::queue<int>()

    std::queue<int>().swap(q)
