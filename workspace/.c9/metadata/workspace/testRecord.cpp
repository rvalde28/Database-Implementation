{"changed":true,"filter":false,"title":"testRecord.cpp","tooltip":"/testRecord.cpp","value":"#include <iostream>\n#include <climits>\n#include \"Record.h\"\n\nusing namespace std;\n\n\nint failDefaultConstructor() {\n    cout << \"- - - - Test Default Contructor - - - -\\n\";\n    Record record;\n    if (record.size() != 0) {\n        return 1;\n    }\n    return 0;\n}\n\nint failSizeConstructor() {\n    cout << \"- - - - Test Size Constructor - - - -\\n\";\n    // FIXME: Prototype test negative - don't know how they will handle this, so not sure how to test\n    try {\n        Record recordNeg(-1);\n        cout << \"Failed to catch negative size\\n\";\n        return 1;\n    }\n    catch (...) {\n        //Good - threw exception\n    }\n    Record record0(0);\n    if (record0.size() != 0) {\n        cout << \"Failed to initialize to 0\\n\";\n        return 1;\n    }\n    Record record3(3);\n    if (record3.size() != 3) {\n        cout << \"Failed to initialize to 3\\n\";\n        return 1;\n    }\n    Record recordMAX(INT_MAX);\n    if (recordMAX.size() != INT_MAX) {\n        cout << \"Failed to initialize to int max\\n\";\n        return 1;\n    }\n    return 0;\n}\n\nint failCopyConstructor() {\n    cout << \"- - - - Test Copy Constructor - - - -\\n\";\n    Record original_record_empty;\n    Record copy_record_empty(original_record_empty);\n    if (copy_record_empty.size() != original_record_empty.size()) {\n        cout << \"Failed copy constructor\\n\";\n        return 1;\n    }\n    Record original_record(4);\n    original_record.set(0, \"Element 0\");\n    original_record.set(1, \"Element 1\");\n    original_record.set(2, \"Element 2\");\n    original_record.set(3, \"Element 3\");\n    Record copy_record(original_record);\n    if (copy_record.size() != original_record.size()) {\n        cout << \"Failed copy constructor\\n\";\n        return 1;\n    }\n    for (int i = 0; i < copy_record.size(); i++) {\n        if (copy_record.get(i) != original_record.get(i)) {\n            cout << \"Failed copy constructor\\n\";\n            return 1;\n        }\n    }\n    return 0;\n}\n\nint failSize() {\n    cout << \"- - - - Test Size  - - - -\\n\";\n    Record record0(0);\n    if (record0.size() != 0) {\n        cout << \"Size failed\\n\";\n        return 1;\n    }\n    Record record25(25);\n    if (record25.size() != 25) {\n        cout << \"Size failed\\n\";\n        return 1;\n    }\n    Record recordMAX(INT_MAX);\n    if (recordMAX.size() != INT_MAX) {\n        cout << \"Size failed\\n\";\n        return 1;\n    }\n    return 0;\n}\n\nint failGet() {\n    cout << \"- - - - Test Get  - - - -\\n\";\n    Record record(3);\n    record.set(0, \"Element 0\");\n    if (record.get(0) != \"Element 0\") {\n        cout << \"Get failed to return 'Element 0'\\n\";\n        return 1;\n    }\n    if (record.get(1) != \"\") {\n        cout << \"Get failed to return NULL\\n\";\n        return 1;\n    }\n    record.set(2, \"Element 2\");\n    if (record.get(2) != \"Element 2\") {\n        cout << \"Get failed to return 'Element 2'\\n\";\n        return 1;\n    }\n    return 0;\n}\n\nint failSet() {\n    cout << \"- - - - Test Set  - - - -\\n\";\n    Record record(3);\n    record.set(0, \"Element 0\");\n    if (record.get(0) != \"Element 0\") {\n        cout << \"Set failed to insert 'Element 0'\\n\";\n        return 1;\n    }\n    record.set(2, \"Element 2\");\n    if (record.get(2) != \"Element 2\") {\n        cout << \"Set failed to insert 'Element 2'\\n\";\n        return 1;\n    }\n    return 0;\n}\n\nint testRecord() {\n    int failCount = 0;\n    cout << \"- - - - Test Record - - - -\\n\";\n    if (failDefaultConstructor()) {\n        failCount++;\n        cout << \"  -- DEFAULT CONSTRUCTOR FAILED --\\n\\n\";\n    }\n    else {\n        cout << \"  -- DEFAULT CONSTRUCTOR PASSED --\\n\\n\";\n    }\n    if (failSizeConstructor()) {\n        failCount++;\n        cout << \"  -- SIZE CONSTRUCTOR FAILED --\\n\\n\";\n    }\n    else {\n        cout << \"  -- SIZE CONSTRUCTOR PASSED --\\n\\n\";\n    }\n    if (failCopyConstructor()) {\n        failCount++;\n        cout << \"  -- COPY CONSTRUCTOR FAILED --\\n\\n\";\n    }\n    else {\n        cout << \"  -- COPY CONSTRUCTOR PASSED --\\n\\n\";\n    }\n    if (failSize()) {\n        failCount++;\n        cout << \"  -- SIZE FAILED --\\n\\n\";\n    }\n    else {\n        cout << \"  -- SIZE PASSED --\\n\\n\";\n    }\n    if (failGet()) {\n        failCount++;\n        cout << \"  -- GET FAILED --\\n\\n\";\n    }\n    else {\n        cout << \"  -- GET PASSED --\\n\\n\";\n    }\n    if (failSet()) {\n        failCount++;\n        cout << \"  -- SET FAILED --\\n\\n\";\n    }\n    else {\n        cout << \"  -- SET PASSED --\\n\\n\";\n    }\n    if (!failCount) {\n        cout << \"- - - - ALL TESTS PASSED - - - -\\n\\n\";\n    }\n    return failCount;\n}","undoManager":{"mark":76,"position":100,"stack":[[{"start":{"row":141,"column":5},"end":{"row":144,"column":5},"action":"insert","lines":["","    else {","        cout << \"  -- QUERY PASSED --\\n\\n\";","    }"],"id":4360}],[{"start":{"row":148,"column":5},"end":{"row":151,"column":5},"action":"insert","lines":["","    else {","        cout << \"  -- QUERY PASSED --\\n\\n\";","    }"],"id":4361}],[{"start":{"row":155,"column":5},"end":{"row":158,"column":5},"action":"insert","lines":["","    else {","        cout << \"  -- QUERY PASSED --\\n\\n\";","    }"],"id":4362}],[{"start":{"row":162,"column":5},"end":{"row":165,"column":5},"action":"insert","lines":["","    else {","        cout << \"  -- QUERY PASSED --\\n\\n\";","    }"],"id":4363}],[{"start":{"row":169,"column":5},"end":{"row":172,"column":5},"action":"insert","lines":["","    else {","        cout << \"  -- QUERY PASSED --\\n\\n\";","    }"],"id":4364}],[{"start":{"row":172,"column":5},"end":{"row":173,"column":0},"action":"insert","lines":["",""],"id":4365},{"start":{"row":173,"column":0},"end":{"row":173,"column":4},"action":"insert","lines":["    "]}],[{"start":{"row":173,"column":4},"end":{"row":173,"column":5},"action":"insert","lines":["i"],"id":4366}],[{"start":{"row":173,"column":5},"end":{"row":173,"column":6},"action":"insert","lines":["f"],"id":4367}],[{"start":{"row":173,"column":6},"end":{"row":173,"column":7},"action":"insert","lines":[" "],"id":4368}],[{"start":{"row":173,"column":7},"end":{"row":173,"column":9},"action":"insert","lines":["()"],"id":4369}],[{"start":{"row":173,"column":8},"end":{"row":173,"column":9},"action":"insert","lines":["!"],"id":4370}],[{"start":{"row":173,"column":9},"end":{"row":173,"column":10},"action":"insert","lines":["f"],"id":4371}],[{"start":{"row":173,"column":10},"end":{"row":173,"column":11},"action":"insert","lines":["a"],"id":4372}],[{"start":{"row":173,"column":11},"end":{"row":173,"column":12},"action":"insert","lines":["i"],"id":4373}],[{"start":{"row":173,"column":12},"end":{"row":173,"column":13},"action":"insert","lines":["l"],"id":4374}],[{"start":{"row":173,"column":13},"end":{"row":173,"column":14},"action":"insert","lines":["C"],"id":4375}],[{"start":{"row":173,"column":14},"end":{"row":173,"column":15},"action":"insert","lines":["o"],"id":4376}],[{"start":{"row":173,"column":15},"end":{"row":173,"column":16},"action":"insert","lines":["u"],"id":4377}],[{"start":{"row":173,"column":16},"end":{"row":173,"column":17},"action":"insert","lines":["n"],"id":4378}],[{"start":{"row":173,"column":17},"end":{"row":173,"column":18},"action":"insert","lines":["t"],"id":4379}],[{"start":{"row":173,"column":19},"end":{"row":173,"column":20},"action":"insert","lines":[" "],"id":4380}],[{"start":{"row":173,"column":20},"end":{"row":173,"column":21},"action":"insert","lines":["{"],"id":4381}],[{"start":{"row":173,"column":21},"end":{"row":175,"column":5},"action":"insert","lines":["","        ","    }"],"id":4382}],[{"start":{"row":174,"column":8},"end":{"row":174,"column":9},"action":"insert","lines":["c"],"id":4383}],[{"start":{"row":174,"column":9},"end":{"row":174,"column":10},"action":"insert","lines":["o"],"id":4384}],[{"start":{"row":174,"column":10},"end":{"row":174,"column":11},"action":"insert","lines":["u"],"id":4385}],[{"start":{"row":174,"column":11},"end":{"row":174,"column":12},"action":"insert","lines":["t"],"id":4386}],[{"start":{"row":174,"column":12},"end":{"row":174,"column":13},"action":"insert","lines":[" "],"id":4387}],[{"start":{"row":174,"column":13},"end":{"row":174,"column":14},"action":"insert","lines":["<"],"id":4388}],[{"start":{"row":174,"column":14},"end":{"row":174,"column":15},"action":"insert","lines":["<"],"id":4389}],[{"start":{"row":174,"column":15},"end":{"row":174,"column":16},"action":"insert","lines":[" "],"id":4390}],[{"start":{"row":174,"column":16},"end":{"row":174,"column":18},"action":"insert","lines":["\"\""],"id":4391}],[{"start":{"row":174,"column":17},"end":{"row":174,"column":18},"action":"insert","lines":["-"],"id":4392}],[{"start":{"row":174,"column":18},"end":{"row":174,"column":19},"action":"insert","lines":[" "],"id":4393}],[{"start":{"row":174,"column":19},"end":{"row":174,"column":20},"action":"insert","lines":["-"],"id":4394}],[{"start":{"row":174,"column":20},"end":{"row":174,"column":21},"action":"insert","lines":[" "],"id":4395}],[{"start":{"row":174,"column":21},"end":{"row":174,"column":22},"action":"insert","lines":["-"],"id":4396}],[{"start":{"row":174,"column":22},"end":{"row":174,"column":23},"action":"insert","lines":[" "],"id":4397}],[{"start":{"row":174,"column":23},"end":{"row":174,"column":24},"action":"insert","lines":["-"],"id":4398}],[{"start":{"row":174,"column":24},"end":{"row":174,"column":25},"action":"insert","lines":[" "],"id":4399}],[{"start":{"row":174,"column":25},"end":{"row":174,"column":26},"action":"insert","lines":["A"],"id":4400}],[{"start":{"row":174,"column":26},"end":{"row":174,"column":27},"action":"insert","lines":["L"],"id":4401}],[{"start":{"row":174,"column":27},"end":{"row":174,"column":28},"action":"insert","lines":["L"],"id":4402}],[{"start":{"row":174,"column":28},"end":{"row":174,"column":29},"action":"insert","lines":[" "],"id":4403}],[{"start":{"row":174,"column":29},"end":{"row":174,"column":30},"action":"insert","lines":["T"],"id":4404}],[{"start":{"row":174,"column":30},"end":{"row":174,"column":31},"action":"insert","lines":["E"],"id":4405}],[{"start":{"row":174,"column":31},"end":{"row":174,"column":32},"action":"insert","lines":["S"],"id":4406}],[{"start":{"row":174,"column":32},"end":{"row":174,"column":33},"action":"insert","lines":["T"],"id":4407}],[{"start":{"row":174,"column":33},"end":{"row":174,"column":34},"action":"insert","lines":["S"],"id":4408}],[{"start":{"row":174,"column":34},"end":{"row":174,"column":35},"action":"insert","lines":[" "],"id":4409}],[{"start":{"row":174,"column":35},"end":{"row":174,"column":36},"action":"insert","lines":["F"],"id":4410}],[{"start":{"row":174,"column":35},"end":{"row":174,"column":36},"action":"remove","lines":["F"],"id":4411}],[{"start":{"row":174,"column":35},"end":{"row":174,"column":36},"action":"insert","lines":["P"],"id":4412}],[{"start":{"row":174,"column":36},"end":{"row":174,"column":37},"action":"insert","lines":["A"],"id":4413}],[{"start":{"row":174,"column":37},"end":{"row":174,"column":38},"action":"insert","lines":["S"],"id":4414}],[{"start":{"row":174,"column":38},"end":{"row":174,"column":39},"action":"insert","lines":["S"],"id":4415}],[{"start":{"row":174,"column":39},"end":{"row":174,"column":40},"action":"insert","lines":["E"],"id":4416}],[{"start":{"row":174,"column":40},"end":{"row":174,"column":41},"action":"insert","lines":["D"],"id":4417}],[{"start":{"row":174,"column":41},"end":{"row":174,"column":42},"action":"insert","lines":[" "],"id":4418}],[{"start":{"row":174,"column":42},"end":{"row":174,"column":43},"action":"insert","lines":["-"],"id":4419}],[{"start":{"row":174,"column":43},"end":{"row":174,"column":44},"action":"insert","lines":[" "],"id":4420}],[{"start":{"row":174,"column":44},"end":{"row":174,"column":45},"action":"insert","lines":["-"],"id":4421}],[{"start":{"row":174,"column":45},"end":{"row":174,"column":46},"action":"insert","lines":[" "],"id":4422}],[{"start":{"row":174,"column":46},"end":{"row":174,"column":47},"action":"insert","lines":["-"],"id":4423}],[{"start":{"row":174,"column":47},"end":{"row":174,"column":48},"action":"insert","lines":[" "],"id":4424}],[{"start":{"row":174,"column":48},"end":{"row":174,"column":49},"action":"insert","lines":["-"],"id":4425}],[{"start":{"row":174,"column":49},"end":{"row":174,"column":50},"action":"insert","lines":["\\"],"id":4426}],[{"start":{"row":174,"column":50},"end":{"row":174,"column":51},"action":"insert","lines":["n"],"id":4427}],[{"start":{"row":174,"column":51},"end":{"row":174,"column":52},"action":"insert","lines":["\\"],"id":4428}],[{"start":{"row":174,"column":52},"end":{"row":174,"column":53},"action":"insert","lines":["n"],"id":4429}],[{"start":{"row":174,"column":54},"end":{"row":174,"column":55},"action":"insert","lines":[";"],"id":4430}],[{"start":{"row":171,"column":22},"end":{"row":171,"column":27},"action":"remove","lines":["QUERY"],"id":4431},{"start":{"row":171,"column":22},"end":{"row":171,"column":25},"action":"insert","lines":["SET"]}],[{"start":{"row":164,"column":22},"end":{"row":164,"column":27},"action":"remove","lines":["QUERY"],"id":4432},{"start":{"row":164,"column":22},"end":{"row":164,"column":25},"action":"insert","lines":["GET"]}],[{"start":{"row":157,"column":22},"end":{"row":157,"column":27},"action":"remove","lines":["QUERY"],"id":4433},{"start":{"row":157,"column":22},"end":{"row":157,"column":26},"action":"insert","lines":["SIZE"]}],[{"start":{"row":150,"column":22},"end":{"row":150,"column":27},"action":"remove","lines":["QUERY"],"id":4434},{"start":{"row":150,"column":22},"end":{"row":150,"column":38},"action":"insert","lines":["COPY CONSTRUCTOR"]}],[{"start":{"row":143,"column":22},"end":{"row":143,"column":27},"action":"remove","lines":["QUERY"],"id":4435},{"start":{"row":143,"column":22},"end":{"row":143,"column":38},"action":"insert","lines":["SIZE CONSTRUCTOR"]}],[{"start":{"row":136,"column":22},"end":{"row":136,"column":27},"action":"remove","lines":["QUERY"],"id":4436},{"start":{"row":136,"column":22},"end":{"row":136,"column":41},"action":"insert","lines":["DEFAULT CONSTRUCTOR"]}],[{"start":{"row":25,"column":10},"end":{"row":25,"column":14},"action":"remove","lines":["pass"],"id":4437},{"start":{"row":25,"column":10},"end":{"row":25,"column":11},"action":"insert","lines":["G"]}],[{"start":{"row":25,"column":11},"end":{"row":25,"column":12},"action":"insert","lines":["o"],"id":4438}],[{"start":{"row":25,"column":12},"end":{"row":25,"column":13},"action":"insert","lines":["o"],"id":4439}],[{"start":{"row":25,"column":13},"end":{"row":25,"column":14},"action":"insert","lines":["d"],"id":4440}],[{"start":{"row":25,"column":14},"end":{"row":25,"column":15},"action":"insert","lines":[" "],"id":4441}],[{"start":{"row":25,"column":15},"end":{"row":25,"column":16},"action":"insert","lines":["="],"id":4442}],[{"start":{"row":25,"column":15},"end":{"row":25,"column":16},"action":"remove","lines":["="],"id":4443}],[{"start":{"row":25,"column":15},"end":{"row":25,"column":16},"action":"insert","lines":["-"],"id":4444}],[{"start":{"row":25,"column":16},"end":{"row":25,"column":17},"action":"insert","lines":[" "],"id":4445}],[{"start":{"row":25,"column":17},"end":{"row":25,"column":18},"action":"insert","lines":["t"],"id":4446}],[{"start":{"row":25,"column":18},"end":{"row":25,"column":19},"action":"insert","lines":["h"],"id":4447}],[{"start":{"row":25,"column":19},"end":{"row":25,"column":20},"action":"insert","lines":["r"],"id":4448}],[{"start":{"row":25,"column":20},"end":{"row":25,"column":21},"action":"insert","lines":["e"],"id":4449}],[{"start":{"row":25,"column":21},"end":{"row":25,"column":22},"action":"insert","lines":["w"],"id":4450}],[{"start":{"row":25,"column":22},"end":{"row":25,"column":23},"action":"insert","lines":[" "],"id":4451}],[{"start":{"row":25,"column":23},"end":{"row":25,"column":24},"action":"insert","lines":["e"],"id":4452}],[{"start":{"row":25,"column":24},"end":{"row":25,"column":25},"action":"insert","lines":["x"],"id":4453}],[{"start":{"row":25,"column":25},"end":{"row":25,"column":26},"action":"insert","lines":["c"],"id":4454}],[{"start":{"row":25,"column":26},"end":{"row":25,"column":27},"action":"insert","lines":["e"],"id":4455}],[{"start":{"row":25,"column":27},"end":{"row":25,"column":28},"action":"insert","lines":["p"],"id":4456}],[{"start":{"row":25,"column":28},"end":{"row":25,"column":29},"action":"insert","lines":["t"],"id":4457}],[{"start":{"row":25,"column":29},"end":{"row":25,"column":30},"action":"insert","lines":["i"],"id":4458}],[{"start":{"row":25,"column":30},"end":{"row":25,"column":31},"action":"insert","lines":["o"],"id":4459}],[{"start":{"row":25,"column":31},"end":{"row":25,"column":32},"action":"insert","lines":["n"],"id":4460}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":25,"column":32},"end":{"row":25,"column":32},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1506912726330}