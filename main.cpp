#include <iostream>
#include <string>

extern "C" {
bool verify_jwt(const char* jwt);
}

// g++ main.cpp -L./target/debug -ltless_jwt
// ./a.out
// $ Verified!
// $ Not verified :-(
int main()
{
    std::string goodJwt = "eyJhbGciOiJSUzI1NiIsImprdSI6Imh0dHBzOi8vZmFhc21hdHRwcm92LmV1czIuYXR0ZXN0LmF6dXJlLm5ldC9jZXJ0cyIsImtpZCI6IkowcEFQZGZYWEhxV1dpbWdySDg1M3dNSWRoNS9mTGUxejZ1U1hZUFhDYTA9IiwidHlwIjoiSldUIn0.eyJleHAiOjE3MjgwOTAxMTMsImlhdCI6MTcyODA2MTMxMywiaXMtZGVidWdnYWJsZSI6dHJ1ZSwiaXNzIjoiaHR0cHM6Ly9mYWFzbWF0dHByb3YuZXVzMi5hdHRlc3QuYXp1cmUubmV0IiwianRpIjoiNmQyNWIyMjNlMmJhMTFkNmExMWY4NWE2Y2RiYzE1NzcwNjE2ODJkMDczM2NmNGM2NWZiYjU4ZWJlODg4YTMzOSIsIm1hYS1hdHRlc3RhdGlvbmNvbGxhdGVyYWwiOnsicWVpZGNlcnRzaGFzaCI6ImE2NGQ2NDkxOTg1MDdkOGI1N2UzM2Y2M2FiMjY2ODM4ZjQzZjMyN2JkNGFhY2M3ODUxMGI2OTc2ZWQwNDZlMTAiLCJxZWlkY3JsaGFzaCI6ImFkZmExOTQyNDIwZTY5ZGY1MTE4ZmYwMDZiNTNhZTFlNWRmZDkxZTVhNTcxMjQyOTczMTI2Yjg2MGFkNWViMTMiLCJxZWlkaGFzaCI6Ijc3MDFmNjQ3MDBiN2Y1MDVkN2I0YjdhOTNlNDVkNWNkZThjZmM4NjViNjBmMWRkNDllY2JlZTk3OTBjMzM3MmUiLCJxdW90ZWhhc2giOiI0NDNmN2JmY2QxN2U0YjI3NmQ1ODI1Nzk0MTJiZmE2YjNjMWI5YTU2N2FlZjE1YmE1ZDJiNDdiZTRhMGVlOWVhIiwidGNiaW5mb2NlcnRzaGFzaCI6ImE2NGQ2NDkxOTg1MDdkOGI1N2UzM2Y2M2FiMjY2ODM4ZjQzZjMyN2JkNGFhY2M3ODUxMGI2OTc2ZWQwNDZlMTAiLCJ0Y2JpbmZvY3JsaGFzaCI6ImFkZmExOTQyNDIwZTY5ZGY1MTE4ZmYwMDZiNTNhZTFlNWRmZDkxZTVhNTcxMjQyOTczMTI2Yjg2MGFkNWViMTMiLCJ0Y2JpbmZvaGFzaCI6IjY4NjRjNjg3NGMyZWYzNmJjOTJlNTg3ZTAwOTMwYmYzZWEwYmM0ODYyZDA2YjBmYmU2YWY4NjMyN2UwNGMzNTcifSwibmJmIjoxNzI4MDYxMzEzLCJwcm9kdWN0LWlkIjowLCJzZ3gtbXJlbmNsYXZlIjoiNjUwNmIzYmI2NmFlMTQ0MWYyYzIwODZlMjM0MGYzNzY2M2YyZDU4ZmJhYTViZDYwMWE3MTFiMDRiNDk3ZTE0NSIsInNneC1tcnNpZ25lciI6IjgzZDcxOWU3N2RlYWNhMTQ3MGY2YmFmNjJhNGQ3NzQzMDNjODk5ZGI2OTAyMGY5YzcwZWUxZGZjMDhjN2NlOWUiLCJzdm4iOjAsInRlZSI6InNneCIsIngtbXMtYXR0ZXN0YXRpb24tdHlwZSI6InNneCIsIngtbXMtcG9saWN5Ijp7ImlzLWRlYnVnZ2FibGUiOnRydWUsInByb2R1Y3QtaWQiOjAsInNneC1tcmVuY2xhdmUiOiI2NTA2YjNiYjY2YWUxNDQxZjJjMjA4NmUyMzQwZjM3NjYzZjJkNThmYmFhNWJkNjAxYTcxMWIwNGI0OTdlMTQ1Iiwic2d4LW1yc2lnbmVyIjoiODNkNzE5ZTc3ZGVhY2ExNDcwZjZiYWY2MmE0ZDc3NDMwM2M4OTlkYjY5MDIwZjljNzBlZTFkZmMwOGM3Y2U5ZSIsInN2biI6MCwidGVlIjoic2d4In0sIngtbXMtcG9saWN5LWhhc2giOiJPd0V2cFNWRVdBNWVpc0NFbmNCdDhOU1pGTFlEUktvTGFvT05Qclpnb2VZIiwieC1tcy1zZ3gtY29sbGF0ZXJhbCI6eyJxZWlkY2VydHNoYXNoIjoiYTY0ZDY0OTE5ODUwN2Q4YjU3ZTMzZjYzYWIyNjY4MzhmNDNmMzI3YmQ0YWFjYzc4NTEwYjY5NzZlZDA0NmUxMCIsInFlaWRjcmxoYXNoIjoiYWRmYTE5NDI0MjBlNjlkZjUxMThmZjAwNmI1M2FlMWU1ZGZkOTFlNWE1NzEyNDI5NzMxMjZiODYwYWQ1ZWIxMyIsInFlaWRoYXNoIjoiNzcwMWY2NDcwMGI3ZjUwNWQ3YjRiN2E5M2U0NWQ1Y2RlOGNmYzg2NWI2MGYxZGQ0OWVjYmVlOTc5MGMzMzcyZSIsInF1b3RlaGFzaCI6IjQ0M2Y3YmZjZDE3ZTRiMjc2ZDU4MjU3OTQxMmJmYTZiM2MxYjlhNTY3YWVmMTViYTVkMmI0N2JlNGEwZWU5ZWEiLCJ0Y2JpbmZvY2VydHNoYXNoIjoiYTY0ZDY0OTE5ODUwN2Q4YjU3ZTMzZjYzYWIyNjY4MzhmNDNmMzI3YmQ0YWFjYzc4NTEwYjY5NzZlZDA0NmUxMCIsInRjYmluZm9jcmxoYXNoIjoiYWRmYTE5NDI0MjBlNjlkZjUxMThmZjAwNmI1M2FlMWU1ZGZkOTFlNWE1NzEyNDI5NzMxMjZiODYwYWQ1ZWIxMyIsInRjYmluZm9oYXNoIjoiNjg2NGM2ODc0YzJlZjM2YmM5MmU1ODdlMDA5MzBiZjNlYTBiYzQ4NjJkMDZiMGZiZTZhZjg2MzI3ZTA0YzM1NyJ9LCJ4LW1zLXNneC1pcy1kZWJ1Z2dhYmxlIjp0cnVlLCJ4LW1zLXNneC1tcmVuY2xhdmUiOiI2NTA2YjNiYjY2YWUxNDQxZjJjMjA4NmUyMzQwZjM3NjYzZjJkNThmYmFhNWJkNjAxYTcxMWIwNGI0OTdlMTQ1IiwieC1tcy1zZ3gtbXJzaWduZXIiOiI4M2Q3MTllNzdkZWFjYTE0NzBmNmJhZjYyYTRkNzc0MzAzYzg5OWRiNjkwMjBmOWM3MGVlMWRmYzA4YzdjZTllIiwieC1tcy1zZ3gtcHJvZHVjdC1pZCI6MCwieC1tcy1zZ3gtcmVwb3J0LWRhdGEiOiI1MmM0YmJjZWViNTkxMjRkNTg0NzQzZTc1MGQ0NmNhN2FiOTU2YzlkZDAzMmU4ODcyYjM3MjcwNWZhOWRlNGUzYTliZTVkZGVkNzM0Yzg1Nzg1NDM0NTNiOWE5OGFjYjQxOTUxNDYzYjUxZGUzNjIzYzRiNjc5NWM1MjYyZmE1MyIsIngtbXMtc2d4LXN2biI6MCwieC1tcy1zZ3gtdGNiaWRlbnRpZmllciI6IjEwIiwieC1tcy12ZXIiOiIxLjAifQ.2MHmljiFFxQzlU3qLHoEGx2wcyvXXOyLUdaMzekYiuG2ZiEh4H-g1PI-TymWpdUFkT-0a2zw06tdP0IOWmbvqF-uSta3wlINN1LmsBapZiLBwxYH2otTvr1z9oy1iRMhe44x_fOplLLmL4buaw4xjm1zqzKtHHpwQUQCWVAyZF9BQ3-yi6ssf-4HYBr-8bvwbxHR8HbAgAdC8meAjkV8Z15V0BF3cnC8hkjbq-OlAAzgFORL6nNpQy_CXp6LgPknInubBECxMU6ybRk-_MI1jqy6Ko-rTHYbAC0bmZiM3VwILDEQDLnT-3EcMfELaYHmRTH7I8LKHbQxDbSOw-ydKA";
    std::string badJwt = "eyJmbmciOiJSUzI1NiIsImprdSI6Imh0dHBzOi8vZmFhc21hdHRwcm92LmV1czIuYXR0ZXN0LmF6dXJlLm5ldC9jZXJ0cyIsImtpZCI6IkowcEFQZGZYWEhxV1dpbWdySDg1M3dNSWRoNS9mTGUxejZ1U1hZUFhDYTA9IiwidHlwIjoiSldUIn0.eyJleHAiOjE3MjgwOTAxMTMsImlhdCI6MTcyODA2MTMxMywiaXMtZGVidWdnYWJsZSI6dHJ1ZSwiaXNzIjoiaHR0cHM6Ly9mYWFzbWF0dHByb3YuZXVzMi5hdHRlc3QuYXp1cmUubmV0IiwianRpIjoiNmQyNWIyMjNlMmJhMTFkNmExMWY4NWE2Y2RiYzE1NzcwNjE2ODJkMDczM2NmNGM2NWZiYjU4ZWJlODg4YTMzOSIsIm1hYS1hdHRlc3RhdGlvbmNvbGxhdGVyYWwiOnsicWVpZGNlcnRzaGFzaCI6ImE2NGQ2NDkxOTg1MDdkOGI1N2UzM2Y2M2FiMjY2ODM4ZjQzZjMyN2JkNGFhY2M3ODUxMGI2OTc2ZWQwNDZlMTAiLCJxZWlkY3JsaGFzaCI6ImFkZmExOTQyNDIwZTY5ZGY1MTE4ZmYwMDZiNTNhZTFlNWRmZDkxZTVhNTcxMjQyOTczMTI2Yjg2MGFkNWViMTMiLCJxZWlkaGFzaCI6Ijc3MDFmNjQ3MDBiN2Y1MDVkN2I0YjdhOTNlNDVkNWNkZThjZmM4NjViNjBmMWRkNDllY2JlZTk3OTBjMzM3MmUiLCJxdW90ZWhhc2giOiI0NDNmN2JmY2QxN2U0YjI3NmQ1ODI1Nzk0MTJiZmE2YjNjMWI5YTU2N2FlZjE1YmE1ZDJiNDdiZTRhMGVlOWVhIiwidGNiaW5mb2NlcnRzaGFzaCI6ImE2NGQ2NDkxOTg1MDdkOGI1N2UzM2Y2M2FiMjY2ODM4ZjQzZjMyN2JkNGFhY2M3ODUxMGI2OTc2ZWQwNDZlMTAiLCJ0Y2JpbmZvY3JsaGFzaCI6ImFkZmExOTQyNDIwZTY5ZGY1MTE4ZmYwMDZiNTNhZTFlNWRmZDkxZTVhNTcxMjQyOTczMTI2Yjg2MGFkNWViMTMiLCJ0Y2JpbmZvaGFzaCI6IjY4NjRjNjg3NGMyZWYzNmJjOTJlNTg3ZTAwOTMwYmYzZWEwYmM0ODYyZDA2YjBmYmU2YWY4NjMyN2UwNGMzNTcifSwibmJmIjoxNzI4MDYxMzEzLCJwcm9kdWN0LWlkIjowLCJzZ3gtbXJlbmNsYXZlIjoiNjUwNmIzYmI2NmFlMTQ0MWYyYzIwODZlMjM0MGYzNzY2M2YyZDU4ZmJhYTViZDYwMWE3MTFiMDRiNDk3ZTE0NSIsInNneC1tcnNpZ25lciI6IjgzZDcxOWU3N2RlYWNhMTQ3MGY2YmFmNjJhNGQ3NzQzMDNjODk5ZGI2OTAyMGY5YzcwZWUxZGZjMDhjN2NlOWUiLCJzdm4iOjAsInRlZSI6InNneCIsIngtbXMtYXR0ZXN0YXRpb24tdHlwZSI6InNneCIsIngtbXMtcG9saWN5Ijp7ImlzLWRlYnVnZ2FibGUiOnRydWUsInByb2R1Y3QtaWQiOjAsInNneC1tcmVuY2xhdmUiOiI2NTA2YjNiYjY2YWUxNDQxZjJjMjA4NmUyMzQwZjM3NjYzZjJkNThmYmFhNWJkNjAxYTcxMWIwNGI0OTdlMTQ1Iiwic2d4LW1yc2lnbmVyIjoiODNkNzE5ZTc3ZGVhY2ExNDcwZjZiYWY2MmE0ZDc3NDMwM2M4OTlkYjY5MDIwZjljNzBlZTFkZmMwOGM3Y2U5ZSIsInN2biI6MCwidGVlIjoic2d4In0sIngtbXMtcG9saWN5LWhhc2giOiJPd0V2cFNWRVdBNWVpc0NFbmNCdDhOU1pGTFlEUktvTGFvT05Qclpnb2VZIiwieC1tcy1zZ3gtY29sbGF0ZXJhbCI6eyJxZWlkY2VydHNoYXNoIjoiYTY0ZDY0OTE5ODUwN2Q4YjU3ZTMzZjYzYWIyNjY4MzhmNDNmMzI3YmQ0YWFjYzc4NTEwYjY5NzZlZDA0NmUxMCIsInFlaWRjcmxoYXNoIjoiYWRmYTE5NDI0MjBlNjlkZjUxMThmZjAwNmI1M2FlMWU1ZGZkOTFlNWE1NzEyNDI5NzMxMjZiODYwYWQ1ZWIxMyIsInFlaWRoYXNoIjoiNzcwMWY2NDcwMGI3ZjUwNWQ3YjRiN2E5M2U0NWQ1Y2RlOGNmYzg2NWI2MGYxZGQ0OWVjYmVlOTc5MGMzMzcyZSIsInF1b3RlaGFzaCI6IjQ0M2Y3YmZjZDE3ZTRiMjc2ZDU4MjU3OTQxMmJmYTZiM2MxYjlhNTY3YWVmMTViYTVkMmI0N2JlNGEwZWU5ZWEiLCJ0Y2JpbmZvY2VydHNoYXNoIjoiYTY0ZDY0OTE5ODUwN2Q4YjU3ZTMzZjYzYWIyNjY4MzhmNDNmMzI3YmQ0YWFjYzc4NTEwYjY5NzZlZDA0NmUxMCIsInRjYmluZm9jcmxoYXNoIjoiYWRmYTE5NDI0MjBlNjlkZjUxMThmZjAwNmI1M2FlMWU1ZGZkOTFlNWE1NzEyNDI5NzMxMjZiODYwYWQ1ZWIxMyIsInRjYmluZm9oYXNoIjoiNjg2NGM2ODc0YzJlZjM2YmM5MmU1ODdlMDA5MzBiZjNlYTBiYzQ4NjJkMDZiMGZiZTZhZjg2MzI3ZTA0YzM1NyJ9LCJ4LW1zLXNneC1pcy1kZWJ1Z2dhYmxlIjp0cnVlLCJ4LW1zLXNneC1tcmVuY2xhdmUiOiI2NTA2YjNiYjY2YWUxNDQxZjJjMjA4NmUyMzQwZjM3NjYzZjJkNThmYmFhNWJkNjAxYTcxMWIwNGI0OTdlMTQ1IiwieC1tcy1zZ3gtbXJzaWduZXIiOiI4M2Q3MTllNzdkZWFjYTE0NzBmNmJhZjYyYTRkNzc0MzAzYzg5OWRiNjkwMjBmOWM3MGVlMWRmYzA4YzdjZTllIiwieC1tcy1zZ3gtcHJvZHVjdC1pZCI6MCwieC1tcy1zZ3gtcmVwb3J0LWRhdGEiOiI1MmM0YmJjZWViNTkxMjRkNTg0NzQzZTc1MGQ0NmNhN2FiOTU2YzlkZDAzMmU4ODcyYjM3MjcwNWZhOWRlNGUzYTliZTVkZGVkNzM0Yzg1Nzg1NDM0NTNiOWE5OGFjYjQxOTUxNDYzYjUxZGUzNjIzYzRiNjc5NWM1MjYyZmE1MyIsIngtbXMtc2d4LXN2biI6MCwieC1tcy1zZ3gtdGNiaWRlbnRpZmllciI6IjEwIiwieC1tcy12ZXIiOiIxLjAifQ.2MHmljiFFxQzlU3qLHoEGx2wcyvXXOyLUdaMzekYiuG2ZiEh4H-g1PI-TymWpdUFkT-0a2zw06tdP0IOWmbvqF-uSta3wlINN1LmsBapZiLBwxYH2otTvr1z9oy1iRMhe44x_fOplLLmL4buaw4xjm1zqzKtHHpwQUQCWVAyZF9BQ3-yi6ssf-4HYBr-8bvwbxHR8HbAgAdC8meAjkV8Z15V0BF3cnC8hkjbq-OlAAzgFORL6nNpQy_CXp6LgPknInubBECxMU6ybRk-_MI1jqy6Ko-rTHYbAC0bmZiM3VwILDEQDLnT-3EcMfELaYHmRTH7I8LKHbQxDbSOw-ydKA";

    if (verify_jwt(goodJwt.c_str())) {
        std::cout << "Verified!" << std::endl;
    } else {
        std::cerr << "Not verified :-(" << std::endl;
    }

    if (verify_jwt(badJwt.c_str())) {
        std::cout << "Verified!" << std::endl;
    } else {
        std::cerr << "Not verified :-(" << std::endl;
    }

    return 0;
}
