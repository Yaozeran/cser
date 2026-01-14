## Light weighted c serialization lib

### Procedure

1. You create a std::iostream.

2. You wrap that stream in a cser::ser or cser::deser.

3. You pass your object to the serializer.

4. The serializer uses traits to find your serialize method.

5. If the method is private, it uses cser::access to get inside.

6. The deserializer pushes those objs into the stream.

### Reference

This architecture is based on cereal lib, for complete code, refer to [cereal](https://github.com/USCiLab/cereal).

This document is for learning purpose only; for commercialized use, plz refer to cereal link above. 
