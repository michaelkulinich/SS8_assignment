import unittest
import mycd_python as cd

class TestMycd(unittest.TestCase):
    def test1(self):
        """# mycd / abc -> /abc"""

        current_dir = "/"
        new_dir = "abc"
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/abc")

    
    def test2(self):
        """# mycd /abc/def /abc -> /abc"""

        current_dir = "/abc/def"
        new_dir = ".."
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/abc")

    def test3(self):
        """# mycd /abc/def .. -> /abc"""

        current_dir = "/abc/def"
        new_dir = "/abc"
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/abc")

    def test4(self):
        """# mycd /abc/def /abc/klm -> /abc/klm"""

        current_dir = "/abc/def"
        new_dir = "/abc/klm"
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/abc/klm")

    def test5(self):
        """# mycd /abc/def ../../.. -> /"""

        current_dir = "/abc/def"
        new_dir = "../../.."
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/")

    def test6(self):
        """# mycd /abc/def . -> /abc/def"""

        current_dir = "/abc/def"
        new_dir = "."
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/abc/def")

    def test7(self):
        """# mycd /abc/def ../gh///../klm/. -> /abc/klm"""

        current_dir = "/abc/def"
        new_dir = "../gh///../klm/."
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/abc/klm")

    def test8(self):
        """# mycd /abc/def ////// -> /"""

        current_dir = "/abc/def"
        new_dir = "//////"
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "/")

    def test9(self):
        """# mycd /abc/def ... -> ...: No such file or directory"""

        current_dir = "/abc/def"
        new_dir = "..."
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "...: No such file or directory")

    def test10(self):
        """# mycd /abc/def klm. -> klm.: No such file or directory"""

        current_dir = "/abc/def"
        new_dir = "klm."
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "klm.: No such file or directory")

    def test11(self):
        """# mycd /abc/def ..klm -> ..klm: No such file or directory"""

        current_dir = "/abc/def"
        new_dir = "..klm"
        result = cd.mycd(current_dir, new_dir)
        self.assertEqual(result, "..klm: No such file or directory")

        
        
if __name__ == '__main__':
    unittest.main()