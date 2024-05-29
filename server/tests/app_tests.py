import unittest
import tornado.web
import tornado.testing
import tornado.testing
import app  # import your tornado application here


class TestMainHandler(tornado.testing.AsyncHTTPTestCase):
    def get_app(self):
        return app.make_app()

    @tornado.testing.gen_test(timeout=10)
    async def test_homepage(self):
        response = await self.fetch('/')
        self.assertEqual(response.code, 200)
        self.assertEqual(response.body, b"Hello, world")
    @tornado.testing.gen_test(timeout=10)
    async def fail_test_homepage(self):
        response = await self.fetch('/')
        self.assertEqual(response.code, 404)
        self.assertEqual(response.body, b"Bye")

# if __name__ == '__main__':
#     tornado.testing.main()
