# leetcode

```
C  c = C();      // Zero initialize using default constructor
C  c{};          // Latest versions accept this syntax.
C* c = new C();  // Zero initialize a dynamically allocated object.

// Note the difference between the above and the initialize version of the constructor.
// Note: All above comments apply to POD structures.
C  c;            // members are random
C* c = new C;    // members are random (more officially undefined).
```
