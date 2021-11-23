# Cache_sim
Run the code by invoking it with "./cache_sim num_entries associativity memory_reference_file"
      an example would be ./cache_sim 4 2 memory_reference_file
   
The code is supposed to simulate how a cache arranges and accesses data.
The code should obtain a memory address by converting an integer number into a valid bit, tag, and index.
It should then access the cache and store the data according to those parameters.
When doing a cache search, it searches by tag. If the entry is found in the cache, it is a "cache hit".
If the entry is not found it is a "cache miss"
The next stage of memory (main memory) is searched if it is not found in the cache.

The code in this repo will only work for a 2 entry, word addressed cache.
A class represents a simple cache.
It does not store data other than the memory address.
