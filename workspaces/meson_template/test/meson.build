test_src = ['test_template.cpp',]
inc = include_directories('../../doctest/doctest')
exe = executable('test_app', ['test_main.cpp', app_src, test_src],
        include_directories : inc, 
        override_options: 'cpp_std=c++17'
      )

test('basic', exe)