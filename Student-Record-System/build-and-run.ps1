# Build and Run Script for Student Record System
# This script sets up the environment, builds the project, runs tests, and executes the application

# Add MinGW to PATH
$env:Path = "C:\mingw64\bin;" + [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

Write-Host "=== Student Record System Build Script ===" -ForegroundColor Cyan
Write-Host ""

# Build the project
Write-Host "Building project..." -ForegroundColor Yellow
cmake --build build --config Release

if ($LASTEXITCODE -ne 0) {
    Write-Host "Build failed!" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Build succeeded!" -ForegroundColor Green
Write-Host ""

# Run tests
Write-Host "Running tests..." -ForegroundColor Yellow
ctest --test-dir build --output-on-failure

if ($LASTEXITCODE -ne 0) {
    Write-Host "Tests failed!" -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "All tests passed!" -ForegroundColor Green
Write-Host ""

# Run the application
Write-Host "Running Student Record System..." -ForegroundColor Yellow
Write-Host ""
.\build\student_record_system.exe

Write-Host ""
Write-Host "=== Complete ===" -ForegroundColor Cyan
